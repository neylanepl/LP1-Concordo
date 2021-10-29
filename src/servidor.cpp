#include "../include/servidor.h"

void Servidor::set_usuarioDonoId( int id ){
    usuarioDonoId = id;
}

int Servidor::get_usuarioDonoId( void ) const{
    return usuarioDonoId;
}

void Servidor::set_nome_server( std::string nome ){
    nome_server = nome;
}
        
std::string Servidor::get_nome_server( void ) const{
    return nome_server;
}

void Servidor::set_descricao_server( std::string descricao ){
    descricao_server = descricao;
}

std::string Servidor::get_descricao_server( void ) const{
    return descricao_server;
}

void Servidor::set_codigoConvite( std::string codigo ){
    codigoConvite = codigo;
}

std::string Servidor::get_codigoConvite( void ) const{
    return codigoConvite;
}

void Servidor::set_canaisTexto(std::string nome){
    int index = canaisTexto.size();
    canaisTexto.resize( index + 1 );
    canaisTexto.at(index).set_nome_canal(nome);
}

void Servidor::set_canais( int indice, int id, std::string mensagem){
    canaisTexto.at(indice).set_mensagens(id, mensagem);
}

std::vector<CanalTexto> Servidor::get_canaisTexto(void) const{
    return canaisTexto;
}

std::vector<int> Servidor::get_participantesIDs(void) const{
    return participantesIDs;
}

void Servidor::set_participantesIDs(int id){
    participantesIDs.push_back(id);
}

void Servidor::erase_participantesIDs( int id){
    if(find(participantesIDs.begin(), participantesIDs.end(), id) != participantesIDs.end()){
        participantesIDs.erase(find(participantesIDs.begin(), participantesIDs.end(), id));
    }
}
