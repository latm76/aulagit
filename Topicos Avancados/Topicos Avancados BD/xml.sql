/*
NOTAS
Namespace útil para diferenciar elementos com mesmo nome mas de origem diferente.
Ex: aluno, origem: uninove, uso, Unicamp
Namespace em geral a url associada
Tipos de dados.
Byte: número inteiro de 8 bits
*/


create table alunoteste (ra number(10),nome varchar(20),estado varchar2(2));

insert into alunoteste values (1,'leonardo','SP');
insert into alunoteste values (2,'ricardo','MG');
insert into alunoteste values (3,'monica','PR');

-- clicar no segundo botao para gerar o XML 
SELECT XMLElement("aluno", 
                   XMLElement("RA", ra),
                   XMLElement("Nome", nome),
                        XMLElement("sigla",estado)) AS "RESULT"
FROM alunoteste

SELECT XMLElement("aluno",
                   XMLATTRIBUTES (ra AS ID, NOME),
                   XMLElement("RA", ra),
                   XMLElement("Nome", nome),
                   XMLElement("sigla",estado)) AS "RESULT"
FROM alunoteste

-- mesmo resultado do anterior usando xmlforest
SELECT XMLElement("aluno",
                   XMLATTRIBUTES (ra AS ID, NOME),
                   XMLForest(ra,nome,estado as sigla)) 
FROM alunoteste


set long 40000
SELECT 
    XMLElement("faculdade", XMLAgg(
        XMLElement("aluno",
                   XMLATTRIBUTES (ra AS ID, NOME),
                   XMLElement("RA", ra),
                   XMLElement("Nome", nome),
                   XMLElement("sigla",estado)))) AS "RESULT"
FROM alunoteste

SELECT DBMS_xmlgen.GETXML ('SELECT * FROM ALUNOTESTE',0)  FROM DUAL


begin
  dbms_xmlschema.registerSchema('order.xsd',
'<xs:schema attributeFormDefault="unqualified" elementFormDefault="qualified" xmlns:xs="http://www.w3.org/2001/XMLSchema">
  <xs:element name="order">
    <xs:complexType>
      <xs:sequence>
        <xs:element type="xs:byte" name="orderId"/>
        <xs:element type="xs:byte" name="customerId"/>
      </xs:sequence>
    </xs:complexType>
  </xs:element>
</xs:schema>');
end;

set serveroutput on

declare
  xml xmltype;
begin
  xml := xmltype('<order>
  <orderId>1</orderId>
  <customerId>123</customerId>
</order>');

  dbms_output.put_line(xml.isSchemaValid('order.xsd'));
end;

-- RETORNO 1 - EM CONFORMIDADE - ok


-- SE DER ERRO USAR OPCAO CONFORME ABAIXO
declare
  xml xmltype;
begin
  xml := xmltype('<order xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:noNamespaceSchemaLocation="order.xsd">
  <orderId>1</orderId>
</order>');

  xmltype.schemaValidate(xml);
end;



begin
  dbms_xmlschema.registerSchema('livro.xsd',
'<xs:schema attributeFormDefault="unqualified" elementFormDefault="qualified" xmlns:xs="http://www.w3.org/2001/XMLSchema">
  <xs:element name="livro">
    <xs:complexType>
      <xs:sequence>
        <xs:element type="xs:byte" name="ISBN"/>
        <xs:element type="xs:string" name="titulo"/>
        <xs:element type="xs:string" name="estilo"/>
      </xs:sequence>
    </xs:complexType>
  </xs:element>
</xs:schema>');
end;


declare
  xml xmltype;
begin
  xml := xmltype('<livro>
  <ISBN>1</ISBN>
  <titulo>123</titulo>
  <estilo>romance</estilo>
</livro>');

  dbms_output.put_line(xml.isSchemaValid('livro.xsd'));
end;

begin
  dbms_xmlschema.registerSchema('livro2.xsd',
'<xs:schema attributeFormDefault="unqualified" elementFormDefault="qualified" xmlns:xs="http://www.w3.org/2001/XMLSchema">
  <xs:element name="livro">
    <xs:complexType>
      <xs:sequence>
        <xs:element type="xs:byte" name="ISBN"/>
        <xs:element type="xs:string" name="titulo"/>
        <xs:element type="xs:string" name="estilo"/>
        <xs:element name="autor">
            <xs:complexType>
                <xs:sequence>        
                <xs:element type="xs:string" name="nome"/>
                <xs:element type="xs:byte" name="idade"/>
                </xs:sequence>
            </xs:complexType>
        </xs:element>
                </xs:sequence>
            </xs:complexType>        
        </xs:element>
</xs:schema>');
end;


declare
  xml xmltype;
begin
  xml := xmltype('<livro>
  <ISBN>1</ISBN>
  <titulo>123</titulo>
  <estilo>romance</estilo>
  <autor><nome>Ricardo</nome><idade>76</idade></autor>
</livro>');

  dbms_output.put_line(xml.isSchemaValid('livro2.xsd'));
end;


declare
  xml xmltype;
begin
  xml := xmltype('<livro>
  <ISBN>1</ISBN>
  <titulo>123</titulo>
  <estilo>romance</estilo>
  <autor><nome>Ricardo</nome><idade>76</idade></autor>
  <autor><nome>Leonardo</nome><idade>54</idade></autor>
</livro>');

  dbms_output.put_line(xml.isSchemaValid('livro2.xsd'));
end;
-- erro pois tem 2 autores
      
begin
  dbms_xmlschema.registerSchema('livro3.xsd',
'<xs:schema attributeFormDefault="unqualified" elementFormDefault="qualified" xmlns:xs="http://www.w3.org/2001/XMLSchema">
  <xs:element name="livro">
    <xs:complexType>
      <xs:sequence>
        <xs:element type="xs:byte" name="ISBN"/>
        <xs:element type="xs:string" name="titulo"/>
        <xs:element type="xs:string" name="estilo"/>
        <xs:element name="autor" maxOccurs="unbounded">
            <xs:complexType>
                <xs:sequence>        
                <xs:element type="xs:string" name="nome"/>
                <xs:element type="xs:byte" name="idade"/>
                </xs:sequence>
            </xs:complexType>
        </xs:element>
                </xs:sequence>
            </xs:complexType>        
        </xs:element>
</xs:schema>');
end;


declare
  xml xmltype;
begin
  xml := xmltype('<livro>
  <ISBN>1</ISBN>
  <titulo>123</titulo>
  <estilo>romance</estilo>
  <autor><nome>Ricardo</nome><idade>76</idade></autor>
  <autor><nome>Leonardo</nome><idade>54</idade></autor>
</livro>');

  dbms_output.put_line(xml.isSchemaValid('livro3.xsd'));
end;      