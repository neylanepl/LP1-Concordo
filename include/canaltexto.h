#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include "mensagem.h"
#include <vector>
#include <string>

class CanalTexto{
	private:
        std::string nome_canal;             // O nome do canal, conforme o comando create-channel
        std::vector<Mensagem> mensagens;    // Um vector com mensagens que foram enviadas neste canal

    public:
        /*! Pega nome_canal e retorna.
			@return a string com o nome do canal.
		*/
        std::string get_nome_canal( void ) const;

        /*! Atribui o nome do canal a variável nome_canal.
			@param nome o nome do canal.
		*/
        void set_nome_canal( std::string nome );

        /*! Atribui a mensagem em um posição do vetor de acordo com o id, data e hora.
			@param id um id válido de algum usuário cadastrado e logado no sistema.
            @param mensagem uma mensagem que foi enviada neste canal.
		*/
        void set_mensagens (int id, std::string mensagem );

        /*! Pega mensagens e retorna.
			@return um o vector mensagem que contém todas as mensagens que foram enviadas neste canal.
		*/
        std::vector<Mensagem> get_mensagens( void ) const;
};

#endif