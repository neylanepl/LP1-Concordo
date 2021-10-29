#include "../include/usuario.h"

Usuario::Usuario(int id, const std::string email, const std::string senha, const std::string nome){
    id_user = id;
    email_user = email;
    senha_user = senha;
    nome_user = nome;
}

int Usuario::get_id_user( void ) const{
    return id_user;
}

std::string Usuario::get_senha_user( void ) const{
    return senha_user;
}

std::string Usuario::get_nome_user( void ) const{
    return nome_user;
}

std::string Usuario::get_email_user( void ) const{
    return email_user;
}
