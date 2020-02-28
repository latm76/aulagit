drop table tem cascade constraints;
drop table aluno cascade constraints;
drop table curso cascade constraints;
drop table disciplina cascade constraints;

create table disciplina (cod number(4), nome varchar(20), constraint xpto1 primary key (cod));

create table curso (cod number(4), nome varchar(25), constraint xpto2 primary key (cod));

create table aluno (ra number(4), nome varchar2(30), codcurso number(4), constraint xpto3 primary key (ra), constraint xpto4 foreign key (codcurso) references curso(cod));

create table tem (ra number(4), cod number(4), constraint xpto5 primary key (ra, cod), constraint xpto6 foreign key (ra) references aluno(ra), constraint xpto7 foreign key (cod) references disciplina(cod));

insert into disciplina values (1, 'Banco de Dados');
insert into disciplina values (2, 'Automato Finito');
insert into disciplina values (3, 'Anatomia');
insert into disciplina values (4, 'Educacao Infantil');

insert into curso values (1, 'Ciencia da Computacao');
insert into curso values (2, 'Pedagogia');
insert into curso values (3, 'Enfermagem');
insert into curso values (4, 'Economia');

insert into aluno values (1,'Leonardo',1);
insert into aluno values (2,'Monica',2);
insert into aluno values (3,'Kaique',3);
insert into aluno values (4,'Beto',null);

insert into tem values (1, 1);
insert into tem values (1, 2);
insert into tem values (2, 4);
