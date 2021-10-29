#ifndef USUARIO_H
#define USUARIO_H
#include <string>

class Usuario{
	private:
        int id_user;            // Um identificador único para o usuário
        std::string senha_user; // A senha cadastrada pelo usuário, conforme o comando create-user 
        std::string nome_user;  // O nome cadastrado pelo usuário, conforme o comando create-user
        std::string email_user; // O email cadastrado pelo usuário, conforme o comando create-user 
    
    public:
        /*! Construtor que atribui os argumentos passados a id_user, senha_user, nome_user e email_user
            @param email o email do usuário informado no comando create-user
			@param senha a senha passada ao comando create-ser
			@param nome o nome do usuário (com espaços) passado ao comando create user 
		*/
        Usuario(int id, const std::string email, const std::string senha, const std::string nome);

        /*! Pega id_user e retorna
			@return o inteiro que identifica o usuário
		*/
        int get_id_user( void ) const;

        /*! Pega senha_user e retorna
			@return uma string a senha cadastrada pelo usuário, conforme o comando create-user
		*/
        std::string get_senha_user( void ) const;
        
        /*! Pega nome_user e retorna
			@return uma string com nome cadastrado pelo usuário, conforme o comando create-user
		*/
        std::string get_nome_user( void ) const;

        /*! Pega email_user e retorna
			@return uma string com o email cadastrado pelo usuário, conforme o comando create-user
		*/
        std::string get_email_user( void ) const;
};

#endif