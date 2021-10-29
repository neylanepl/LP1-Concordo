# Projeto 02 - Concordo
Implementação de um Clone do Backend do Discord, com interface textual. 

Realizado pelas alunas: Luma de Abreu Fragoso e Neylane Pereira Lopes.

## Categorias do Projeto
O projeto está organizado da seguinte forma:

```
trabalho-02-neylanepl       ---> Pasta do projeto.
├── build                   ---> Pasta que contém os arquivos executáveis.            
├── data                    ---> Pasta que contém os arquivos de entrada do projeto.
│   ├── nossos_testes.txt   ---> Arquivo com nossos testes.
│   ├── nossos_testes2.txt  ---> Arquivo com nossos testes.
│   └── script_comandos.txt ---> Arquivo com teste exemplo do professor.
├── include                 ---> Pasta que contém os headers '.h' do projeto.
│   ├── canaltexto.h        ---> Arquivo com header de 'canaltexto.cpp'
│   ├── colors.h            ---> Arquivo com elementos para alteração de cor
│   ├── executor.h          ---> Arquivo com header de 'executor.cpp'
│   ├── mensagem.h          ---> Arquivo com header de 'mensagem.cpp'
│   ├── servidor.h          ---> Arquivo com header de 'servidor.cpp'
│   ├── sistema.h           ---> Arquivo com header de 'sistema.cpp'
│   └── usuario.h           ---> Arquivo com header de 'usuario.cpp'
├── src                     ---> Pasta que que contém os arquivos '.cpp' do projeto.
│   ├── canaltexto.cpp      ---> Arquivo com metodos para canaltexto
│   ├── concordo.cpp        ---> Arquivo com a função main
│   ├── executor.cpp        ---> Arquivo que executa o sistema
│   ├── mensagem.cpp        ---> Arquivo com metodos para mensagem
│   ├── servidor.cpp        ---> Arquivo com metodos para servidor
│   ├── sistema.cpp         ---> Arquivo com metodos para sistema
│   └── usuario.cpp         ---> Arquivo com metodos para usuario
├── CMakeLists.txt          ---> Arquivo do cmake
├── Makefile                ---> Arquivo makefile
└── README.md               ---> Instruções para compilar e executar o programa.
```
# Compilando e Executando
A compilação e execução do projeto pode ser feita usando *cmake* ou utizando *makefiles*.

## Como compilar o projeto
Escolha uma das duas formas de build e ignore a outra.
### Usando cmake

1. Entre na pasta do projeto, no caso `trabalho-02-neylanepl`.
```console
cd trabalho-02-neylanepl
```

2. Crie a pasta `build`.
```console
mkdir build
```

3. Entre na pasta `build`.
```console
cd build
```

4. Execute o comando do *cmake* para gerar os arquivos intermediários.
```console
cmake ..
```
   **Possivél saída:**
   
```
            -- Configuring done
            -- Generating done
            -- Build files have been written to: /home/runner/LP1/trabalho-02-neylanepl/build
```
5. Execute o comando do *cmake* para compilar o projeto. Assim, a pasta build conterá os arquivos *Makefile* e o executável *concordo*.
```console
cmake --build .
```
   **Possivél saída:**

```
            Consolidate compiler generated dependencies of target concordo
            [ 12%] Building CXX object CMakeFiles/concordo.dir/src/concordo.cpp.o
            [ 25%] Building CXX object CMakeFiles/concordo.dir/src/sistema.cpp.o
            [ 37%] Building CXX object CMakeFiles/concordo.dir/src/usuario.cpp.o
            [ 50%] Building CXX object CMakeFiles/concordo.dir/src/servidor.cpp.o
            [ 62%] Building CXX object CMakeFiles/concordo.dir/src/mensagem.cpp.o
            [ 75%] Building CXX object CMakeFiles/concordo.dir/src/canaltexto.cpp.o
            [ 87%] Building CXX object CMakeFiles/concordo.dir/src/executor.cpp.o
            [100%] Linking CXX executable concordo
            [100%] Built target concordo
```

### Usando makefiles

1. Entre na pasta do projeto, no caso `trabalho-02-neylanepl`.
```console
cd trabalho-02-neylanepl
```

2. Crie a pasta `build`.
```console
mkdir build
```

3. Execute o comando abaixo para compilar o programa:
```console
make
```
   **Possivél saída:**

```
            g++ -Iinclude src/sistema.cpp -c -o build/sistema.o
            g++ -Iinclude src/executor.cpp -c -o build/executor.o
            g++ -Iinclude src/canaltexto.cpp -c -o build/canaltexto.o
            g++ -Iinclude src/mensagem.cpp -c -o build/mensagem.o
            g++ -Iinclude src/servidor.cpp -c -o build/servidor.o
            g++ -Iinclude src/usuario.cpp -c -o build/usuario.o
            g++ -Wall -fsanitize=address -Iinclude build/sistema.o build/executor.o build/canaltexto.o build/mensagem.o build/servidor.o build/usuario.o src/concordo.cpp -o build/concordo
```

4. Entre na pasta `build`.
```console
cd build
```

## Como executar o projeto

1. Você pode rodar o sistema e logo depois digitar os comandos seguidos de ENTER
```console
./concordo
```

2. Ou pode criar um arquivo de texto com uma lista de comandos (um por linha) e executar o sistema redirecionando esse arquivo como entrada padrão:
```console
./concordo < script_comandos.txt
```

## Como executar o conjunto dos testes planejados

Rode o executável *concordo* e forneça como argumento o arquivo de teste. Dessa forma, é necessário informar o endereço do arquivo de teste a partir da pasta que ele se encontra. 

Neste caso, serão executados alguns arquivos de teste que se encontram na pasta `data`. Como exemplo, foi feito a execução dos arquivos de testes nomeados *nossos_testes.txt* e *script_comandos.txt*. 

Os comandos ficaram do seguinte modo:

```console
./concordo < ../data/nossos_testes.txt
```

```console
./concordo < ../data/nossos_testes2.txt
```

```console
./concordo < ../data/script_comandos.txt
```

# Limitações ou funcionalidades não implementadas no programa

Analisando as implementações realizadas, acredita-se que todas as funcionalidades esperadas foram desenvolvidas. Além disso, não foi encontrada nehuma limitação no programa.

