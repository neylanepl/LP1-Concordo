#include "../include/canaltexto.h"

std::string CanalTexto::get_nome_canal( void ) const{
    return nome_canal;
}

void CanalTexto::set_nome_canal( std::string nome ){
    nome_canal = nome;
}

std::vector<Mensagem> CanalTexto::get_mensagens( void ) const{
    return mensagens;
}

void CanalTexto::set_mensagens( int id, std::string mensagem){
    int index = mensagens.size();
    mensagens.resize( index + 1 );
    mensagens.at(index).set_enviadaPor(id);
    mensagens.at(index).set_conteudo(mensagem);
    mensagens.at(index).set_dataHora();
}