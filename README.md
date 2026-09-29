# 🗂️ Sistema de Cadastro de Pessoas em C++ com MySQL

Aplicação de console desenvolvida em **C++** que se conecta a um banco de dados **MySQL** (via WampServer) e cadastra pessoas com nome, e-mail e idade. Projeto criado durante minha graduação em Análise e Desenvolvimento de Sistemas para praticar a integração entre programação e banco de dados.

## ✨ O que o programa faz

- Conecta ao MySQL local usando a API C oficial (`mysql.h`)
- Recebe nome, e-mail e idade pelo terminal
- Grava os dados na tabela `pessoas` com um comando `INSERT`
- Informa o sucesso da operação ou o erro retornado pelo MySQL (`mysql_error`), inclusive quando a conexão falha

## 💻 Exemplo de execução

```
[SUCESSO] Conectado ao MySQL via WampServer!

=== CADASTRO DE PESSOAS ===
Nome: Maria Silva
Email: maria@email.com
Idade: 25

[SUCESSO] Pessoa cadastrada com sucesso!
```

<!-- Depois de adicionar os prints ao repositório, remova os comentários abaixo:
![Programa rodando](tela-cadastro.png)
![Registro salvo no banco](banco-mysql.png)
-->

## 🛠️ Tecnologias

- **C++** (Dev-C++ 5.11, compilador GCC 4.9.2 64 bits)
- **MySQL 8.4** (servidor local pelo WampServer)
- **API C do MySQL** (`mysql.h` e `libmysql`)

## 🧠 O que pratiquei neste projeto

- Conexão entre uma aplicação C++ e um banco de dados relacional
- Execução de comandos SQL a partir do código
- Tratamento de erros de conexão e de consulta
- Configuração do ambiente: pastas de include e lib do MySQL, linkagem com `-lmysql` e resolução de dependências de DLL

## 🗄️ Banco de dados

O script `banco.sql` cria o banco `sistemas_cadastro` e a tabela `pessoas`. Importe-o pelo phpMyAdmin (aba **Importar**) ou pelo cliente do MySQL.

## ▶️ Como executar

**Pré-requisitos:** WampServer (64 bits) com o MySQL ativo e um compilador C++ (Dev-C++ ou g++).

1. Clone o repositório:
   ```bash
   git clone https://github.com/ItsmeEduu/NOME-DO-REPOSITORIO.git
   ```
2. Inicie o WampServer e importe o `banco.sql`.
3. Compile apontando para as pastas do MySQL (ajuste o caminho conforme a versão instalada):
   ```bash
   g++ main.cpp -o cadastro.exe -I"C:/wamp64/bin/mysql/mysql8.4.7/include" -L"C:/wamp64/bin/mysql/mysql8.4.7/lib" -lmysql
   ```
4. Copie para a mesma pasta do `cadastro.exe` as DLLs necessárias:
   - `libmysql.dll`, da pasta `lib` do MySQL do WampServer
   - `libssl-3-x64.dll` e `libcrypto-3-x64.dll`, da pasta `bin` do Apache do WampServer
5. Execute o `cadastro.exe`.

> ℹ️ A conexão usa `127.0.0.1`, usuário `root` e senha vazia, que é a configuração padrão do WampServer para desenvolvimento local. Em um ambiente real, use um usuário próprio com senha.

## 🚧 Limitações e próximos passos

- [ ] Listar, buscar, editar e excluir registros (CRUD completo)
- [ ] Usar consultas parametrizadas (*prepared statements*): hoje o `INSERT` é montado por concatenação de texto, o que permite SQL injection. É a melhoria prioritária.
- [ ] Validar os dados digitados (por exemplo, idade não numérica)
- [ ] Menu em repetição, para cadastrar vários registros sem reiniciar o programa
- [ ] Tirar os dados de conexão de dentro do código

## 📫 Autor

**Eduardo Ferreira de Souza** · [LinkedIn](https://www.linkedin.com/in/itsmeeduu)
