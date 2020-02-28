drop table dependente cascade constraints;
drop table tem cascade constraints;
drop table empregado cascade constraints;
drop table gerente cascade constraints;
drop table cargo cascade constraints;
drop table desconto cascade constraints;
Drop table funcionario cascade constraints;

create table funcionario (mat number(3), nome varchar2(30), apelido varchar2(10), salario number(9), desconto number(9), cod number(3), constraint funcionario_pk primary key (mat));

Create table gerente ( 
	CPF number(11), 
	nome varchar(50), 
	obs varchar(100) default 'Terceirizado', 
	CONSTRAINT gerente_pk PRIMARY KEY(CPF) 
);

Create table cargo(
	cod char(1) CONSTRAINT cargo_ch CHECK (cod='C' OR cod='G' OR cod='D'), 
	nome varchar(30) not null, 
	CONSTRAINT cargo_pk PRIMARY KEY(cod)
) ;

Create table desconto (
	cod number(10), 
	sigla char(5) not null, 
	CONSTRAINT desc_pk PRIMARY KEY(cod) 
);

Create table empregado (
	mat number(10), 
	CPF number(11) unique not null, 
	nome varchar(60), 
	idade number(2) CONSTRAINT emp_chk CHECK (idade between 18 and 75),
	CPFger number(11) , 
	cod char(1), 
	datager date, 
	datacargo date, 
	CONSTRAINT emp_pk PRIMARY KEY(mat), 
	CONSTRAINT emp_fk FOREIGN KEY(CPFger) REFERENCES gerente(CPF) ON DELETE SET NULL, 
	CONSTRAINT emp2_fk FOREIGN KEY(cod) REFERENCES cargo(cod) 
);

Create table tem (
	mat number(10), 
	cod number(10), 
	valor number(18,2), 
	CONSTRAINT tem_pk PRIMARY KEY(mat, cod), 
	CONSTRAINT tem2_fk FOREIGN KEY(mat) REFERENCES empregado(mat), 
	CONSTRAINT tem3_fk FOREIGN KEY(cod) REFERENCES desconto (cod) 
);

Create table dependente (
	cod number(4), 
	nome varchar2(50), 
	parentesco varchar2(20), 
	mat number(10), 
	CONSTRAINT dependente_pk PRIMARY KEY(cod), 
	CONSTRAINT dependente2_fk FOREIGN KEY(mat) REFERENCES empregado(mat) ON DELETE CASCADE
);


insert into gerente (CPF, nome) values (1,'Gerente#1');
insert into gerente (CPF, nome) values (2,'Gerente#2');
insert into gerente (CPF, nome) values (3,'Gerente#3');
insert into gerente (CPF, nome) values (11,'Gerente#11');

insert into cargo values ('C', 'Consultor');
insert into cargo values ('G', 'Gerente');
insert into cargo values ('D', 'Diretor');

insert into desconto values (1,'IR');
insert into desconto values (2,'INSS');
insert into desconto values (3,'VALE');
insert into desconto values (4,'SAUDE');

insert into empregado (mat,CPF,nome,CPFger, cod) values (1,1,'Empregado#1',1,'C');
insert into empregado (mat,CPF,nome,CPFger, cod) values (2,2,'Empregado#2',2,'G');
insert into empregado (mat,CPF,nome,CPFger, cod) values (3,3,'Empregado#3',3,'C');
insert into empregado (mat,CPF,nome,CPFger, cod) values (40,4,'Empregado#40',1,'D');
insert into empregado (mat,CPF,nome,CPFger, cod) values (50,5,'Empregado#50',2,'C');
insert into empregado (mat,CPF,nome,CPFger, cod) values (60,6,'Empregado#60',3,'C');
insert into empregado (mat,CPF,nome,CPFger, cod) values (101,7,'Empregado#101',1,'G');
insert into empregado (mat,CPF,nome,CPFger, cod) values (301,9,'Empregado#301',3,'C');

insert into tem (mat, cod, valor) values (1,1,290.80);
insert into tem (mat, cod, valor) values (1,2,100);
insert into tem (mat, cod, valor) values (1,3,65);
insert into tem (mat, cod, valor) values (1,4,140);

insert into tem (mat, cod, valor) values (2,1,340);
insert into tem (mat, cod, valor) values (2,2,200);
insert into tem (mat, cod, valor) values (2,3,165);
insert into tem (mat, cod, valor) values (2,4,70);

insert into tem (mat, cod, valor) values (40,1,340);
insert into tem (mat, cod, valor) values (40,2,200);

insert into tem (mat, cod, valor) values (101,1,100);
insert into tem (mat, cod, valor) values (101,2,300);
insert into tem (mat, cod, valor) values (101,4,210);

insert into funcionario values(1,'AnA','A',900,100,1);
insert into funcionario values(2,'MAriaNA','MA',11000,150,2);
insert into funcionario values (3,'JOaNA UMSILVA','JO',1200,120,1);
insert into funcionario values(4,'leonardo','leo',2000,250,5);
insert into funcionario values(5,'RICARDO','caco',2400,300,1);
insert into funcionario values(6,'kaique','kk',3000,500,5);
insert into funcionario values(7,'TAIS sILVA','tata',4000,500,1);
insert into funcionario values(8,'RITA SILVA bARROCO','ri',5000,700,2);
insert into funcionario values(9,'ANDREIA BArrOCO','deia',3000,600,null);
insert into funcionario values(10,'MONICA SIlvANA BARROS','moni',3000,400,null);
