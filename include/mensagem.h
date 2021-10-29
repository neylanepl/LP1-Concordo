#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>
#include <chrono>
#include <iostream>
#include <ctime>
#include <iomanip> // para put_time

using namespace std;
using namespace std::chrono;

class Mensagem{
    private:
        std::string dataHora;   // Um texto representando um timestamp com a data e hora em que a mensagem foi enviada
        int enviadaPor;         // Id do usuário que enviou a mensagem
        std::string conteudo;   // Conteúdo da mensagem

    public:
        /*! Pega dataHora e retorna.
			@return a string com a data e o horário em que a mensagem foi enviada.
		*/
        std::string get_dataHora( void ) const;

        /*! Atribui a data e a hora a variável dataHora .*/
        void set_dataHora( void );

        /*! Pega enviadaPor e retorna.
			@return um inteiro que contém o id do usuário que enviou a mensagem..
		*/
        int get_enviadaPor( void ) const;

        /*! Atribui o id a variável enviadaPor.
			@param id um id válido de algum usuário cadastrado e logado no sistema.
		*/
        void set_enviadaPor( int id );
        
        /*! Pega conteudo e retorna.
			@return a string com o conteúdo da mensagem.
		*/
        std::string get_conteudo( void ) const;

        /*! Atribui o conteúdo da mensagem enviada a variável conteudo.
			@param cont o conteúdo da mensagem enviada.
		*/
        void set_conteudo( std::string cont);
};

#endif