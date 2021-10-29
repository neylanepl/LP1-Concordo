#include "../include/mensagem.h"

std::string Mensagem::get_dataHora( void ) const{
    return dataHora;
}

void Mensagem::set_dataHora( void ){
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    if ( now->tm_mday < 10){
        dataHora += "<0" + std::to_string(now->tm_mday ) + "/";
    }
    else{
        dataHora += "<" + std::to_string(now->tm_mday ) + "/";
    }

    if(now->tm_mon + 1 < 10){
        dataHora += "0" + std::to_string(now->tm_mon + 1);
    }
    else{
        dataHora += std::to_string(now->tm_mon + 1);
    }

    dataHora += "/" + std::to_string(now->tm_year + 1900) + " - ";

    if( now->tm_hour < 10){
        dataHora += "0" + std::to_string(now->tm_hour) + ":";
    }
    else{
        dataHora += std::to_string(now->tm_hour) + ":";
    }
    
    if(now->tm_min < 10){
        dataHora += "0" + std::to_string(now->tm_min) + ">: ";
    }
    else{
        dataHora += std::to_string(now->tm_min) + ">: ";
    }
}

int Mensagem::get_enviadaPor( void ) const{
    return enviadaPor;
}

void Mensagem::set_enviadaPor( int id ){
    enviadaPor = id;
}

std::string Mensagem::get_conteudo( void ) const{
    return conteudo;
}

void Mensagem::set_conteudo( std::string cont){
    conteudo = cont;
}