XML com nested table
Note que uma tabela aninhada gera o codigo XML de modo natural, correto - apenas 1 linha relacionada a Alice - 111, enquanto que a solução com junção não fica bom - gera duas linhas relacionadas a Alice - 111

INSERT INTO cliente_loja VALUES (111, 'ALICE',
lista_enderecos(
t_endereco('RUA FELICIDADE', 100, 'SAO PAULO','SP', '00000-000'),
t_endereco('RUA ALEGRIA', 200, 'RIO DE JANEIRO','RJ', '11111-111')
)
);

-- show de bola
select dbms_xmlgen.getxml(
'SELECT * FROM cliente_loja',0)
from dual

-- é.... meia boca
select dbms_xmlgen.getxml(
'SELECT c.codigo, c.nome, e.*
FROM cliente_loja c, TABLE(c.enderecos_clientes) e',0)
from dual


XML com array

CREATE OR REPLACE TYPE telefones
IS VARRAY (5)
OF VARCHAR2(10);

CREATE TABLE fornecedor_loja (
codigo NUMBER(5),
nome VARCHAR2(50),
tels_fornecedor telefones);

INSERT INTO fornecedor_loja VALUES (111, 'ALICE',
telefones('7777-7777', '2222-2222','98350-7788'));


-- ficou muito bom. so ficou ruim porque saiu varchar2
select dbms_xmlgen.getxml(
'select codigo, nome, tels_fornecedor as telefone from fornecedor_loja',0)
from dual


-- ruim
select dbms_xmlgen.getxml(
'select a.codigo, a.nome, e.column_value as tel from fornecedor_loja a,table(tels_fornecedor) e',0)
from dual

---------------------
CREATE OR REPLACE TYPE numtel
as object(
numtelefone VARCHAR2(10));

CREATE OR REPLACE TYPE telefones2
IS VARRAY (5)
OF numtel;

CREATE TABLE fornecedor_loja2 (
codigo NUMBER(5),
nome VARCHAR2(50),
tels_fornecedor telefones2);

INSERT INTO fornecedor_loja2 VALUES (111, 'ALICE',
telefones2(numtel('7777-7777'), numtel('2222-2222'),numtel('98350-7788')));

select dbms_xmlgen.getxml(
'select codigo, nome, tels_fornecedor as telefone from fornecedor_loja2',0)
from dual

----------------------------------
-- XML com child, um unico funcionario com vários dependentes

create table funcionario (mat number(10), nome varchar2(20));
create table dependente (nome varchar(20),mat number(10));

insert into funcionario values (1,'leonardo');
insert into funcionario values (2,'ricardo');
insert into funcionario values (3,'tais');

insert into dependente values ('Fernanda',1);
insert into dependente values ('Luiza',1);
insert into dependente values ('Monica',1);
insert into dependente values ('Alana',2);

set long 40000

SELECT
  XMLElement(
    "Funcionario",
    XMLAttributes(f.nome AS "NomeFunc"),
        (SELECT XMLAgg(XMLElement("dependente",
                XMLAttributes(d.nome AS "nomedep") ))
            FROM dependente d
            WHERE d.mat = f.mat))
  FROM funcionario f;
 
 -- da erro pois para leonardo retorna mais de 1 linha. O XMLAgg faz justamente o agrupamento de todas linhas numa só
SELECT
f.nome AS "NomeFunc",
        (SELECT d.nome AS "nomedep"
            FROM dependente d
            WHERE d.mat = f.mat)
  FROM funcionario f;
------------------------

SELECT
  XMLElement(
    "Funcionario",
    XMLATTRIBUTES (f.nome AS "NOME"),
        (SELECT XMLAgg(XMLElement("dependente",
                XMLElement("Nome",d.nome) ))
            FROM dependente d
            WHERE d.mat = f.mat))
  FROM funcionario f;
