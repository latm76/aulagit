CREATE OR REPLACE TYPE t_endereco AS OBJECT (
rua VARCHAR2(50),
numero INTEGER,
cidade VARCHAR2(50),
uf CHAR(2),
cep CHAR(9));

CREATE TYPE lista_enderecos AS TABLE OF t_endereco;

CREATE TABLE cliente_loja (
codigo NUMBER(5),
nome VARCHAR2(50),
enderecos_clientes lista_enderecos)
NESTED TABLE  enderecos_clientes 
STORE AS enderecos_clientes_tab;

INSERT INTO cliente_loja VALUES (111, 'ALICE',
lista_enderecos(
t_endereco('RUA FELICIDADE', 100, 'SAO PAULO','SP', '00000-000'),
t_endereco('RUA ALEGRIA', 200, 'RIO DE JANEIRO','RJ', '11111-111')
)
);

INSERT INTO cliente_loja VALUES (112, 'leonardo',
lista_enderecos(
t_endereco('RUA MONICA', 100, 'SAO CAETANO','SP', '00000-000'),
t_endereco('RUA FERNANDA', 200, 'NITEROI','RJ', '11111-111')
)
);

select * from cliente_loja;

SELECT c.codigo, c.nome, e.rua
FROM cliente_loja c, TABLE(c.enderecos_clientes) e;

SELECT c.codigo, c.nome,e.*
FROM cliente_loja c, TABLE(c.enderecos_clientes) e;

-- nao permite consultar dados oriundos de tabela aninhada
select * from enderecos_clientes_tab;
