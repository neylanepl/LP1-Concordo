#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <vector>
#include <string>
#include <algorithm>
#include "canaltexto.h"

class Servidor{
    private:
        int usuarioDonoId;                  // Id do usuário que criou o servidor
        std::string nome_server;            // Nome do servidor, passado no comando create-server
        std::string descricao_server;       // Descrição do servidor passada no comando set-server-desc
        std::string codigoConvite;          // O código de convite do servidor, se houver
        std::vector<CanalTexto> canaisTexto;// Um vetor contendo todos os canais de texto deste servidor
        std::vector<int> participantesIDs;  // Um vetor contendo os ids de todos os participantes deste servidor.

    public:
        /*! Atribui o id a variável usuarioDonoId.
			@param id Id do usuário que criou o servidor
		*/
        void set_usuarioDonoId( int id );

        /*! Pega usuarioDonoId e retorna
			@return o inteiro que identifica o usuário que criou o servidor
		*/
        int get_usuarioDonoId( void ) const;
        
        /*! Atribui o nome a variável nome_server.
			@param nome nome do servidor, passado no comando create-server
		*/
        void set_nome_server( std::string nome );

        /*! Pega nome_server e retorna
			@return uma string com o nome do servidor, passado no comando create-server
		*/
        std::string get_nome_server( void ) const;

        /*! Atribui a descrição a variável descricao_server.
			@param descricao descrição do servidor passada no comando set-server-desc
		*/
        void set_descricao_server( std::string descricao );

        /*! Pega descricao_server e retorna
			@return uma string com a descrição do servidor passada no comando set-server-desc
		*/
        std::string get_descricao_server( void ) const;

        /*! Atribui o codigo a variável codigoConvite.
			@param codigo o código de convite do servidor, se houver
		*/
        void set_codigoConvite( std::string codigo );

        /*! Pega codigoConvite e retorna
			@return uma string com o código de convite do servidor, se houver
		*/
        std::string get_codigoConvite( void ) const;

        /*! Atribui o nome a variável canaisTexto.
			@param nome nome do canal de texto
		*/
        void set_canaisTexto(std::string nome);

        /*! Pega canaisTexto e retorna
			@return um vetor contendo todos os canais de texto deste servidor
		*/
        std::vector<CanalTexto> get_canaisTexto(void) const;

        /*! Atribui a mensagem a variável mensagens em determinado indice de canaisTexto.
			@param indice posição em canaisTexto em que se quer enviar a mensagem
            @param id Id com a pessoa que enviou a mensagem
            @param mensagem mensagem a ser enviada
		*/
        void set_canais( int indice, int id, std::string mensagem);

        /*! Pega participantesIDs e retorna
			@return um vetor contendo os ids de todos os participantes deste servidor
		*/
        std::vector<int> get_participantesIDs(void) const;

        /*! Atribui o id a variável participantesIDs.
            @param id Id do participante do canal de texto
		*/
        void set_participantesIDs(int id);

        /*! Apaga o id a variável participantesIDs.
            @param id Id do participante do canal de texto
		*/
        void erase_participantesIDs( int id );
};

#endif
