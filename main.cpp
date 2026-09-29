#include <sstream>
#include <string>
#include <iostream>
#include <mysql.h>

int main() {
    
    MYSQL* conn;
    conn = mysql_init(0);

    
    conn = mysql_real_connect(conn, "127.0.0.1", "root", "", "sistemas_cadastro", 3306, NULL, 0);

    if (conn) {
        std::cout << "[SUCESSO] Conectado ao MySQL via WampServer!\n\n";

        std::string nome, email;
        int idade;

        std::cout << "=== CADASTRO DE PESSOAS ===\n";
        std::cout << "Nome: ";
        std::getline(std::cin, nome);

        std::cout << "Email: ";
        std::getline(std::cin, email);

        std::cout << "Idade: ";
        std::cin >> idade;

        // Monta a instrucao SQL de INSERT
       std::ostringstream oss;
			oss << idade;
			std::string query = "INSERT INTO pessoas (nome, email, idade) VALUES ('" + nome + "', '" + email + "', " + oss.str() + ");";
        // Executa a query no banco de dados
        if (mysql_query(conn, query.c_str()) == 0) {
            std::cout << "\n[SUCESSO] Pessoa cadastrada com sucesso!\n";
        } else {
            std::cout << "\n[ERRO] Falha ao cadastrar: " << mysql_error(conn) << "\n";
        }

        // Fecha a conexao com o banco
        mysql_close(conn);
    } else {
        std::cout << "[ERRO] Falha de conexao: " << mysql_error(conn) << "\n";
    }

    return 0;
}
