-- Banco de dados do Sistema de Cadastro de Pessoas (C++ com MySQL)
-- Importe este arquivo pelo phpMyAdmin (aba Importar) ou pelo cliente do MySQL.

CREATE DATABASE IF NOT EXISTS sistemas_cadastro
  CHARACTER SET utf8mb4
  COLLATE utf8mb4_unicode_ci;

USE sistemas_cadastro;

CREATE TABLE IF NOT EXISTS pessoas (
  id    INT AUTO_INCREMENT PRIMARY KEY,
  nome  VARCHAR(100) NOT NULL,
  email VARCHAR(100) NOT NULL,
  idade INT NOT NULL
);
