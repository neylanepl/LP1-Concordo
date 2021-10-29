#include "../include/sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include "../include/colors.h"
using namespace std;

string Sistema::quit(){
  return "Saindo...";
}

bool Sistema::check_email(const string email){
    for (int i = 0; i < usuarios.size(); i++){ // Percorre a quantidade de usuários cadastrados
        if(email == usuarios.at(i).get_email_user()){ // Pega o email do vector na posição i
            return false;
        }
    }
    return true;
}

string Sistema::create_user (const string email, const string senha, const string nome){   
    if(check_email(email)){ // Caso o usuário não foi cadastrado ainda
        Usuario user(usuarios.size(), email, senha, nome);
        usuarios.push_back(user);
        return "Criando usuário " + nome + " (" + email + ")..." + "\n" + BOLD(FGRN("Usuário criado\n"));
    }
    return BOLD(FRED("Falha ao cadastrar usuário: ")) "Usuário já existe!\n"; // Caso o usuário já esteja cadastrado com o email
}

string Sistema::login(const string email, const string senha) {
    for(int i = 0; i < usuarios.size(); i++){ // Percorre a quantidade de usuários cadastrados
        if((email == usuarios.at(i).get_email_user()) && (senha == usuarios.at(i).get_senha_user())){ // Email e senha já criados e corretos
        
            usuariosLogados.insert(std::pair<int, std::pair<std::string, std::string>> (usuarios.at(i).get_id_user(), std::pair<std::string, std::string>("", ""))); // Adiciona ao map o usuário logado
            return "Logando...\n" BOLD(FGRN("Logado como " + email + "\n"));
        }
    }
    return BOLD(FRED("Falha no login: "))"Senha ou usuário inválidos!\n"; 
}

string Sistema::disconnect(int id){
    int i = find_id(id); // Acha a posição do id na Classe Usuário

    if(check_login(id)){ // Caso o id esteja logado
        usuariosLogados.erase(usuariosLogados.find(id)); // Apaga o id do map de usuários logados
        return "Desconectando...\n" BOLD(FGRN("Usuário " + usuarios.at(i).get_email_user() + " desconectado\n"));
    }
    return BOLD(FRED("Falha na conexão: ")) + usuarios.at(i).get_email_user() + " não está conectado!\n"; // Caso o id não esteja logado
}

bool Sistema::check_login(int id){
    if(usuariosLogados.find(id) != usuariosLogados.end()){ // Caso o id esteja logado
        return true;
    }
    return false;
}

int Sistema::find_id(int id){
    int i;
    for(i = 0; i < usuarios.size(); i++){ // Percorre a quantidade de usuários cadastrados
        if(id == usuarios.at(i).get_id_user()){ // Caso ache o id do usuário na lista de usuários
            break;
        }
    }
    return i;
}

string Sistema::create_server(int id, const string nome) {
    if(check_login(id)){ // Verifica se o usuário está logado
        Servidor server;
        for(int i = 0; i < servidores.size(); i++){ // Percorre de acordo com a quantidade de servidores
            if(nome == servidores.at(i).get_nome_server()){ // Caso já exista servidor com esse nome
                return BOLD(FRED("Falha ao cadastrar servidor: ")) "Servidor com esse nome já existe!\n";
            }
        }
        server.set_usuarioDonoId(id);   // Coloca o ID do usuário criador
        server.set_nome_server(nome);   // Coloca o nome do servidor
        servidores.push_back(server);   // Adiciona o servidor no vector de servidores
        
        return "Criando servidor " + nome + "..." + "\n" + BOLD(FGRN("Servidor criado\n")); // Caso não exista servidor com esse nome
    }
    return BOLD(FRED("Falha na conexão: ")) + usuarios.at(find_id(id)).get_email_user() + " não está conectado!\n"; // Usuário não está logado
}

string Sistema::set_server_desc(int id, const string nome, const string descricao){
    if(check_login(id)){ // Verifica se o usuário está logado
        for(int i = 0; i < servidores.size(); i++){ // Percorre de acordo com a quantidade de servidores
            if((id == servidores.at(i).get_usuarioDonoId()) && (nome == servidores.at(i).get_nome_server())){ // Acesso liberado
                servidores.at(i).set_descricao_server(descricao);
                return "Modificando descrição do servidor...\n" BOLD(FGRN("Descrição do servidor " + nome + " modificada\n"));
            }
            else if((id != servidores.at(i).get_usuarioDonoId()) && (nome == servidores.at(i).get_nome_server())){ // Caso tente acessar o servidor que não é do id usuário
                return BOLD(FRED("Falha na mudança da descrição: ")) "Você não pode alterar a descrição de um servidor que não foi criado por você!\n";
            }
        }
        return BOLD(FRED("Falha na mudança da descrição: "))  "Servidor " + nome + " não existe!\n"; // Caso não exista o servidor
    }
    return BOLD(FRED("Falha na conexão: ")) + usuarios.at(find_id(id)).get_email_user() + " não está conectado!\n"; // Usuário não está logado
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {
    if(check_login(id)){// Verifica se o usuário está logado
        for(int i = 0; i < servidores.size(); i++){ // Percorre de acordo com a quantidade de servidores
            if((id == servidores.at(i).get_usuarioDonoId()) && (nome == servidores.at(i).get_nome_server())){ // Verifica se o usuário é dono do servidor
                servidores.at(i).set_codigoConvite(codigo);
                if(codigo != ""){ // Caso o código não seja vazio
                    return "Modificando código de convite do servidor...\n" BOLD(FGRN("Código de convite do servidor " + nome + " modificado\n"));
                }
                else{ // Caso o código seja vazio
                    return "Removendo código de convite do servidor...\n" BOLD(FGRN("Código de convite do servidor " + nome + " removido\n"));
                }
            }
            else if((id != servidores.at(i).get_usuarioDonoId()) && (nome == servidores.at(i).get_nome_server())){ // Caso tente acessar o servidor que não é do id usuário
                return BOLD(FRED("Falha na mudança do código de convite: ")) "Você não pode alterar o código de um servidor que não foi criado por você!\n";
            }
        }
        return BOLD(FRED("Falha na mudança do código de convite: "))  "Servidor " + nome + " não existe!\n"; // Caso não exista o servidor
    }
   return BOLD(FRED("Falha na conexão: ")) + usuarios.at(find_id(id)).get_email_user() + " não está conectado!\n"; // Usuário não está logado
}

string Sistema::list_servers(int id){
    if(check_login(id)){// Verifica se o usuário está logado
        std::string nomes_servers;
        nomes_servers += BOLD(FBLU("#Lista de Servidores\n"));
        for(int i = 0; i < servidores.size(); i++){ // Percorre de acordo com a quantidade de servidores
            if(id == servidores.at(i).get_usuarioDonoId()){ // Pega os servidores com o id passado
                nomes_servers += "-> "+ servidores.at(i).get_nome_server() + "\n"; // Concatena a string
            }
        }
        return nomes_servers; // Retorna a string com os nomes concatenados + \n
    }
    return BOLD(FRED("Falha na conexão: ")) + usuarios.at(find_id(id)).get_email_user() + " não está conectado!\n"; // Usuário não está logado
}

string Sistema::remove_server(int id, const string nome) {
    if(check_login(id)){// Verifica se o usuário está logado
        for(int i = 0; i < servidores.size(); i++){ // Percorre de acordo com a quantidade de servidores
            if((id == servidores.at(i).get_usuarioDonoId()) && (nome == servidores.at(i).get_nome_server())){ // Acesso liberado, pois é o dono do servidor
                if(usuariosLogados.find(id)->second.first == nome){
                    usuariosLogados.find(id)->second.first = "";
                    usuariosLogados.find(id)->second.second = "";
                }
                
                servidores.erase(servidores.begin()+i);
                return "Removendo servidor...\n" BOLD(FGRN("Servidor '" + nome + "' removido\n"));
            }
            else if((id != servidores.at(i).get_usuarioDonoId()) && (nome == servidores.at(i).get_nome_server())){ // Caso tente acessar o servidor que não é do id usuário
                return BOLD(FRED("Falha em remover servidor: ")) "Você não é o dono do servidor '" + nome + "'!" + "\n";
            }
        }
        return BOLD(FRED("Falha em remover servidor: ")) "Servidor '" + nome + "' não encontrado!\n"; // Caso não exista o servidor
    }
    return BOLD(FRED("Falha na conexão: ")) + usuarios.at(find_id(id)).get_email_user() + " não está conectado!\n"; // Usuário não está logado
}

string Sistema::enter_server(int id, const string nome, const string codigo) {
    if(check_login(id)){ // Verifica se o usuário está logado
        for(int i = 0; i < servidores.size(); i++){
            if(nome == servidores.at(i).get_nome_server()){ // Acha o nome do servidor
                if(id == servidores.at(i).get_usuarioDonoId()){ // Independente do código é vazio, id é dono
                    servidores.at(i).set_participantesIDs(id);
                    usuariosLogados.at(id).first = nome;
                    return "Validando código...\nEntrando no servidor...\n" BOLD(FGRN("Entrou no servidor com sucesso\n"));
                }
                if(servidores.at(i).get_codigoConvite() == ""){ // Caso o código convite seja vazio
                    if(codigo == ""){ // Se código vazio
                        servidores.at(i).set_participantesIDs(id);
                        usuariosLogados.at(id).first = nome;
                        return "Validando código...\nEntrando no servidor...\n" BOLD(FGRN("Entrou no servidor com sucesso\n"));
                    }                        
                    else if(codigo != ""){ // Se não é código vazio
                        return BOLD(FRED("Falha no código: "))"Servidor aberto! Não é necessário informar nenhum código!\n";
                    }
                }
                else if(servidores.at(i).get_codigoConvite() != ""){ // Caso o código convite não seja vazio
                    if(codigo == servidores.at(i).get_codigoConvite()){ // Se código não é vazio, e certo
                        servidores.at(i).set_participantesIDs(id);
                        usuariosLogados.at(id).first = nome;
                        return "Validando código...\nEntrando no servidor...\n" BOLD(FGRN("Entrou no servidor com sucesso\n"));
                    }
                    else if(codigo == ""){ // Se código é vazio
                        return BOLD(FRED("Falha no código: ")) "Servidor requer código de convite!\n";
                    }
                    else if(codigo != servidores.at(i).get_codigoConvite()){ // Se código não é vazio, e errado
                        return BOLD(FRED("Falha no código: ")) "Código inserido está incorreto!\n";
                    }
                }
            }
        }
        return BOLD(FRED("Falha no servidor: ")) "Servidor '" + nome + "' não encontrado!\n"; // Caso não exista o servidor
        
    }
    return BOLD(FRED("Falha na conexão: ")) + usuarios.at(find_id(id)).get_email_user() + " não está conectado!\n"; // Usuário não está logado
}

string Sistema::leave_server(int id, const string nome) {
    if(check_login(id)){// Verifica se o usuário está logado
        if(usuariosLogados.find(id)->second.first == ""){ // Caso o usuário não esteja logado em algim servidor
            return BOLD(FRED("Falha na conexão: ")) "Você não está visualizando nenhum servidor!\n";
        }
        else if(usuariosLogados.find(id)->second.first != nome){ //Caso o usuário não esteja logado em servidor específico
            return BOLD(FRED("Falha no login do server: ")) "Você não está visualizando esse servidor!\n";
        }
        else if(usuariosLogados.find(id)->second.first == nome){ // Caso o usuário esteja logado em algm servidor
            usuariosLogados.find(id)->second.first = "";
            usuariosLogados.find(id)->second.second = "";
            
            for(int i = 0; i < servidores.size(); i++){
                if(nome == servidores.at(i).get_nome_server()){ // Procura servidor com esse nome
                    servidores.at(i).erase_participantesIDs(id);
                    return "Saindo do servidor...\n" BOLD(FGRN("Saiu do servidor '"+ nome +"'\n"));
                }
            }
        }
    }
    return BOLD(FRED("Falha na conexão: ")) + usuarios.at(find_id(id)).get_email_user() + " não está conectado!\n"; // Usuário não está logado
}

string Sistema::list_participants(int id) {
    if(check_login(id)){// Verifica se o usuário está logado
        std::string nomes_participantes;
        nomes_participantes += BOLD(FBLU("#Nome(s) Participante(s) \n"));
        if(usuariosLogados.find(id) != usuariosLogados.end()){ // Vê se o id nos usuários logados
            for(int i = 0; i < servidores.size(); i++){ // Percorre de acordo com a quantidade de servidores
                if(servidores.at(i).get_nome_server() == usuariosLogados.find(id)->second.first){ // Caso o nome do servidor seja o nome que o id está olhando
                    for(int j = 0; j < usuarios.size(); j++){
                        for(int k = 0; k < servidores.at(i).get_participantesIDs().size(); k++){
                            if(usuarios.at(j).get_id_user() == servidores.at(i).get_participantesIDs().at(k)){
                                nomes_participantes += "-> " + usuarios.at(j).get_nome_user() + "\n"; // Concatena a string
                            }
                        }
                    }
                }
            }
            return nomes_participantes;
        }
    }
    return BOLD(FRED("Falha na conexão: ")) + usuarios.at(find_id(id)).get_email_user() + " não está conectado!\n"; // Usuário não está logado
}

string Sistema::list_channels(int id) {
    if(check_login(id)){// Verifica se o usuário está logado
    std::string nomes_canais;
        nomes_canais += BOLD(FBLU("#Canais de Texto \n"));
        for(int i = 0; i < servidores.size(); i++){ // Percorre de acordo com a quantidade de servidores
            if(servidores.at(i).get_nome_server() == usuariosLogados.find(id)->second.first){ // Caso o nome do servidor seja o nome que o id está olhando
                for(int k = 0; k < servidores.at(i).get_canaisTexto().size(); k++){
                    nomes_canais += "-> "+ servidores.at(i).get_canaisTexto().at(k).get_nome_canal() + "\n"; // Concatena a string
                }
            }
        }
        return nomes_canais;
    }
    return BOLD(FRED("Falha na conexão: ")) + usuarios.at(find_id(id)).get_email_user() + " não está conectado!\n"; // Usuário não está logado
}

string Sistema::create_channel(int id, const string nome) {
    if(check_login(id)){// Verifica se o usuário está logado
        for(int i = 0; i < servidores.size(); i++){
            if(servidores.at(i).get_canaisTexto().size() == 0){ // Caso não exista um canal de texto criado ainda
                servidores.at(i).set_canaisTexto(nome);
                return "Criando canal de texto...\n" BOLD(FGRN("Canal de texto " + nome + " criado\n"));
            }
            for(int j = 0; j < servidores.at(i).get_canaisTexto().size(); j++){
                if(usuariosLogados.find(id)->second.first == servidores.at(i).get_nome_server()){ // Caso o usuário esteja logado no servidor == nome
                    if( nome != servidores.at(i).get_canaisTexto().at(j).get_nome_canal()){ // Não existe canal texto com esse nome
                        servidores.at(i).set_canaisTexto(nome);
                        return "Criando canal de texto...\n" BOLD(FGRN("Canal de texto " + nome + " criado\n"));
                    }
                    else{ // Existe canal texto com esse nome
                        return BOLD(FRED("Falha no cadastro do canal: "))"Canal de texto " + nome + " já existe!\n";
                    }
                }
            }
        }
    }
    return BOLD(FRED("Falha na conexão: ")) + usuarios.at(find_id(id)).get_email_user() + " não está conectado!\n"; // Usuário não está logado
}

string Sistema::enter_channel(int id, const string nome) {
    if(check_login(id)){// Verifica se o usuário está logado
        for(int i = 0; i < servidores.size(); i++){
            if(servidores.at(i).get_nome_server() == usuariosLogados.find(id)->second.first){ // Caso o usuário esteja logado no servidor == nome
                for(int j = 0; j < servidores.at(i).get_canaisTexto().size(); j++){
                    if(nome == servidores.at(i).get_canaisTexto().at(j).get_nome_canal()){ // Existe canal texto com esse nome
                        usuariosLogados.at(id).second = nome;
                        return "Entrando no canal...\n" BOLD(FGRN("Entrou no canal '" + nome + "'\n"));
                    }
                }
                return BOLD(FRED("Falha na conexão do canal: ")) "Canal '" + nome + "' não existe!\n";
            }     
        }
    }
    return BOLD(FRED("Falha na conexão: ")) + usuarios.at(find_id(id)).get_email_user() + " não está conectado!\n"; // Usuário não está logado
}

string Sistema::leave_channel(int id){
    if(check_login(id)){ // Verifica se o usuário está logado
        if(usuariosLogados.find(id)->second.second == ""){ // Caso não esteja em nenhum canal
            return BOLD(FRED("Falha na saída: "))"Você não está em nenhum canal!\n";
        }
        usuariosLogados.find(id)->second.second = ""; // Caso esteja em um canal, assim reflete que não está mais visualizando nenhum canal
        return BOLD(FGRN("Saindo do canal\n"));
    }
    return BOLD(FRED("Falha na conexão: ")) + usuarios.at(find_id(id)).get_email_user() + " não está conectado!\n"; // Usuário não está logado
}

string Sistema::send_message(int id, const string mensagem) {
    if(check_login(id)){// Verifica se o usuário está logado
        if((usuariosLogados.find(id)->second.first != "") && (usuariosLogados.find(id)->second.second != "")){ // Está logado em algum servidor
            for(int i = 0; i < servidores.size(); i++){
                if(servidores.at(i).get_nome_server() == usuariosLogados.find(id)->second.first){ // Caso o usuário esteja logado no servidor == nome
                    for(int j = 0; j < servidores.at(i).get_canaisTexto().size(); j++){
                        if(servidores.at(i).get_canaisTexto().at(j).get_nome_canal() == usuariosLogados.find(id)->second.second){ // Caso o usuário esteja logado no canal de texto
                            servidores.at(i).set_canais(j, id, mensagem);
                            return "Enviando mensagem...\n" BOLD(FGRN("Mensagem enviada"))"\n";
                        }
                    }
                }
            }
        }
    }
    return BOLD(FRED("Falha na conexão: ")) + usuarios.at(find_id(id)).get_email_user() + " não está conectado!\n"; // Usuário não está logado
}

void Sistema::print_messages(int i, int j) {
    std::cout << BOLD(FBLU("#Mensagens do Canal \n"));
    for(int k = 0; k < servidores.at(i).get_canaisTexto().at(j).get_mensagens().size(); k++){
        for (int l = 0; l < usuarios.size(); l++){ // Percorre a quantidade de usuários cadastrados
            if( usuarios.at(l).get_id_user()  == servidores.at(i).get_canaisTexto().at(j).get_mensagens().at(k).get_enviadaPor()){ // Pega o email do vector na posição i
                std::cout << usuarios.at(l).get_nome_user()
                          << servidores.at(i).get_canaisTexto().at(j).get_mensagens().at(k).get_dataHora()
                          << servidores.at(i).get_canaisTexto().at(j).get_mensagens().at(k).get_conteudo()
                          << "\n";
            }
        }
    }
}

string Sistema::list_messages(int id) {
    if(check_login(id)){// Verifica se o usuário está logado
        if((usuariosLogados.find(id)->second.first != "") && (usuariosLogados.find(id)->second.second != "")){ // Está logado em algum local
            for(int i = 0; i < servidores.size(); i++){
                if(servidores.at(i).get_nome_server() == usuariosLogados.find(id)->second.first){ // Caso o usuário esteja logado no servidor == nome
                    for(int j = 0; j < servidores.at(i).get_canaisTexto().size(); j++){ 
                        if(servidores.at(i).get_canaisTexto().at(j).get_nome_canal() == usuariosLogados.find(id)->second.second){ // Caso nome do canal seja igual ao nome do canal que o usuário está logado
                            if(servidores.at(i).get_canaisTexto().at(j).get_mensagens().size() == 0){ // Caso não possua mensagens
                                return "Sem mensagens para exibir\n";
                            }
                            print_messages(i, j);
                        }
                    }
                }
            }
        }
        return "";
    }
    return BOLD(FRED("Falha na conexão: ")) + usuarios.at(find_id(id)).get_email_user() + " não está conectado!\n"; // Usuário não está logado
}