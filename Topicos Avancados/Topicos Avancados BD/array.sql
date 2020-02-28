CREATE OR REPLACE TYPE telefones
IS VARRAY (5)
OF VARCHAR2(10);

CREATE TABLE fornecedor_loja (
codigo NUMBER(5),
nome VARCHAR2(50),
tels_fornecedor telefones);

INSERT INTO fornecedor_loja VALUES (111, 'ALICE',
telefones('7777-7777', '2222-2222')
);

select * from fornecedor_loja

SELECT c.codigo, c.nome,e.*
FROM FORNECEDOR_LOJA c, TABLE(c.tels_fornecedor) e;

set serveroutput on

DECLARE
 TYPE assoc_array IS TABLE OF VARCHAR2(30)
 INDEX BY VARCHAR2(30);
 
 estado_array assoc_array;
BEGIN
  estado_array('SP') := 'São Paulo';
  estado_array('RJ') := 'Rio de Janeiro';
  estado_array('MG') := 'Minas Gerais';
  estado_array('PR') := 'Paraná';
  dbms_output.put_line(estado_array('SP'));
  dbms_output.put_line(estado_array('RJ'));
  dbms_output.put_line(estado_array('MG'));
  dbms_output.put_line(estado_array('PR'));
END;

create or replace function retorna_estado 
( sigla in varchar)
return varchar
is
 TYPE assoc_array IS TABLE OF VARCHAR2(30)
 INDEX BY VARCHAR2(30);
 estado_array assoc_array;
BEGIN
  estado_array('SP') := 'São Paulo';
  estado_array('RJ') := 'Rio de Janeiro';
  estado_array('MG') := 'Minas Gerais';
  estado_array('PR') := 'Paraná';
  return estado_array(sigla);
END retorna_Estado;

select retorna_estado('SP') from dual;

create table alunoteste (ra number(10),nome varchar(20),estado varchar2(2));

insert into alunoteste values (1,'leonardo','SP');
insert into alunoteste values (2,'ricardo','MG');
insert into alunoteste values (3,'monica','PR');

select ra,nome, retorna_Estado(estado) from alunoteste;
commit