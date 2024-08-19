# Projeto Final - Jogos de tabuleiro

Este projeto implementa um conjunto de jogos de tabuleiro clássicos utilizando C++, permitindo que dois jogadores se enfrentem em uma partida. Os jogos disponíveis incluem:

 - Tic Tac Toe (Jogo da Velha)
 - Reversi
 - Connect Four (Lig4)

Cada jogo foi estruturado fazendo uso de  herança e polimorfismo para facilitar a reutilização de código e garantir uma fácil extensão para outros jogos futuros. Para mais, ainda foi desenvolvido um sistema de cadastro e gerenciamento de jogadores.

> [Clique aqui para ter acesso à documentação](https://luizfelipegondim.github.io/documentation/)

# Como iniciar o projeto?

Para iniciar o programa no seu computador, utilize os seguintes comandos:

 1. Instale o software *make*  caso não tenha instalado na sua máquina;
 2. Em seguida, clone o repositório e o acesse pelo terminal;
 3. Compile o código digitando **make** no terminal;
 4. Para executar o código compilado, digite **bin/./start_game**;
 5. Para executar os testes, digite **make test**;
 6. Para limpar os arquivos compilados, digite **make clean**.

# Estrutura do Projeto

A estrutura do projeto é modular, com classes específicas para cada jogo derivadas da classe base Game. A classe GameBoard gerencia a interface com os jogadores e controla o fluxo geral do programa. Principais Arquivos:

 - **Player.hpp/cpp:** Armazena e gerencia quaisquer dados relacionados aos jogadores.
 -  **Game.hpp/cpp:** Define a classe abstrata base para os jogos, incluindo a lógica comum para todos os jogos, como a criação e a impressão do tabuleiro e verificação de preenchimento do tabuleiro.
 -  **GameBoard.hpp/cpp:** Controla o registro dos jogadores, a leitura/escrita de dados dos jogadores em arquivos, e o início das partidas entre jogadores.
 - **TicTacToe.hpp/cpp:** Implementa o jogo Tic Tac Toe, incluindo a lógica para verificar vitórias e processar jogadas.
 -  **Reversi.hpp/cpp:** Implementa o jogo Reversi, com métodos específicos para gerenciar as regras de captura de peças e contagem de peças no tabuleiro.
 - **ConnectFour.hpp/cpp:** Implementa o jogo Connect Four, com métodos específicos para gerenciar as condições de vitoria e jogada válidas
 
 Ademais, o projeto também é composto pelos arquivos de teste que são responsáveis por testar cada classe e suas funcionalidades.

# Fluxo do software
Nessa seção iremos apresentar como o software funciona para o usuário final. É importante destacar que não foi utilizada uma interface gráfica para a sua execução, sendo feita apenas o uso do terminal do sistema operacional. 

 1. O software inicia sua execução lendo os jogadores que foram cadastrados previamente no arquivo players.txt. Caso esse arquivo ainda não exista, uma mensagem será emitida avisando sobre isso e continuará a execução do programa. Em seguida, o menu de opções será apresentado.

>     Erro na leitura do arquivo: players.txt 
>     Iniciando o sistema com nenhum jogador cadastrado.
>     
>     Escolha uma opção para interagir com o tabuleiro:
>     CJ - Cadastrar jogador
>     RJ - Remover jogador
>     LJ - Listar jogadores
>     EP - Entrar na partida
>     FS - Sair do tabuleiro

2. **CJ - Cadastrar jogador:** Essa opção é utilizada para cadastrar um jogador no sistema solicitando o apelido e o nome ao usuário. Caso esse apelido já tenha sido cadastrado, ocorrerá um erro e o programa voltará para o menu de opções.

>     //Caso de sucesso
>     CJ
>     Informe o apelido e o nome do jogador, respectivamente:
>     Joao Carlos
>     Jogador Joao cadastrado com sucesso!
>     
>     //Caso de falha
>     CJ  
>     Informe o apelido e o nome do jogador, respectivamente:
>     Luiz Felipe
>     ERRO: Jogador existente!

3. **RJ - Remover jogador:** Esta opção irá remover o jogador que possui o apelido informado. Caso este jogador não exista, aparecerá uma mensagem de erro.

>     //Caso de sucesso
>     RJ
>     Informe o apelido do jogador a ser removido:
>     Gabriel
>     Jogador Gabriel removido com sucesso!
>     
>     //Caso de falha
>     RJ  
>     Informe o apelido do jogador a ser removido:
>     Fulano
>     ERRO: Jogador não encontrado!

4. **LJ - Listar jogadores:** Esta função irá listar os jogadores cadastrados considerando a ordem informada. É apresentado o apelido, o nome e informações de vitórias/derrotas de cada jogo da aplicação.

>     LJ
>     Informe um método de ordenação: [Apelido|Nome]
>     TESTE
>     ERRO: Informe um método de ordenação válido: [Apelido|Nome]
>     nome
>     
>     Joao Carlos
>     REVERSI   - V: 0 D: 0
>     LIG4      - V: 0 D: 0
>     TICTACTOE - V: 0 D: 0
>     
>     Luiz Felipe
>     REVERSI   - V: 0 D: 0
>     LIG4      - V: 0 D: 0
>     TICTACTOE - V: 0 D: 0

5. **EP - Entrar na partida:** Esta função é utilizada para iniciar um dos três jogos. O usuário deve escolher qual jogo será executado e em seguida informar os dois jogadores que irão participar da partida.

>     EP
>     Informe o jogo: [Reversi|Lig4|TicTacToe]
>     Minecraft
>     ERRO:Informe um jogo válido: [Reversi|Lig4|TicTacToe]
>     Lig4
>     Informe o apelido do primeiro jogador:
>     Luiz
>     Informe o apelido do segundo jogador:
>     Joao

6. **FS - Sair do tabuleiro:** Ao pressionar ctrl+D ou digitar FS no menu de opções, o programa será finalizado, salvando todos os jogadores no arquivo players.txt. Lembrando que se ele for finalizado de forma abrupta, com ctrl+D, uma mensagem de erro irá aparecer.

>     FS
>     Finalizando o tabuleiro...

7. **Reversi:** O jogo Reversi irá apresentar o seguinte tabuleiro a cada jogada realizada (linha,  coluna) alternando os jogadores, mostrando o contador de peças logo abaixo. Caso seja informada uma coordenada que não obedeça as regras do jogo ou que ultrapasse o tamanho do tabuleiro, uma mensagem de erro será impressa e o jogador terá uma nova chance para jogar. Além desses casos, pode ocorrer a situação onde um jogador não tenha posições possíveis para jogar, então passará a vez. O fim da partida ocorre quando não há mais espaços a serem preenchidos no tabuleiro ou algum jogador perca todas as peças, sendo assim, o jogador com mais peças ganha. O número -1 pode ser impresso para desistência. 

>         1   2   3   4   5   6   7   8  
>     1 |   |   |   |   |   |   |   |   | 
>     2 |   |   |   |   |   |   |   |   | 
>     3 |   |   |   |   |   |   |   |   | 
>     4 |   |   |   | X | O |   |   |   | 
>     5 |   |   |   | O | X |   |   |   | 
>     6 |   |   |   |   |   |   |   |   | 
>     7 |   |   |   |   |   |   |   |   | 
>     8 |   |   |   |   |   |   |   |   | 
>     -------------------------------------
>     |      X = 2      |      O = 2      |
>     -------------------------------------
>     Luiz (X), faça sua jogada (linha e coluna):
>     
>     1 2
>     ERRO: Não tem peça oposta adjacente.
>     Vez de Luiz jogar(X):
>     
>     1 9
>     ERRO: Posição fora dos limites do tabuleiro!
>     Vez de Luiz jogar(X):
>     
>     -1
>     Luiz desistiu, vitória de Joao.
>     
>     //Vitória sem desistência
>     Parabéns Joao! Você venceu!
>     
>     //Empate
>     O jogo terminou em empate!
>     
>     //Um jogador não possui coordenadas para jogar
>     Nao há jogadas possíveis para o(a) jogador(a) Luiz 

8. **Lig4:** O jogo será iniciado com uma lista de possíveis tamanhos para o tabuleiro na qual uma deve ser selecionada. Logo em seguida, será apresentado o tabuleiro que receberá o número de uma coluna para efetuar a jogada dos jogadores de forma alternada. Caso seja informada uma coluna que não obedeça as regras do jogo ou que ultrapasse o tamanho do tabuleiro, uma mensagem de erro será impressa e o jogador terá uma nova chance para jogar. Ganha quem formar um quarteto primeiro (vertical, horizontal ou diagonal), caso isso não aconteça, a partida terminará em empate. Para mais, a cada interação, será mostrado acima do tabuleiro a quantidade de formas que o jogador corrente pode ganhar.

>     Escolha o tamanho do Tabuleiro:
>     1. 5x6
>     2. 6x7
>     3. 7x8
>     Digite o número da opção desejada:
>     1
>     
>     Possíveis formas de ganhar para X: 0
>       1   2   3   4   5   6  
>     |   |   |   |   |   |   | 
>     |   |   |   |   |   |   | 
>     |   |   |   |   |   |   | 
>     |   |   |   |   |   |   | 
>     |   |   |   |   |   |   | 
>     --------------------------
>     Turno de Luiz (X): 8
>     ERRO:Posição fora dos limites do tabuleiro!
>     
>     //Erro de coluna
>     Coluna cheia. Tente novamente!
>     
>     //Vitória
>     Possíveis formas de ganhar para X: 3
>       1   2   3   4   5   6  
>     |   |   |   |   |   |   | 
>     | X |   |   |   |   |   | 
>     | X | O |   |   |   |   | 
>     | X | O |   |   |   |   | 
>     | X | O |   |   |   |   | 
>     --------------------------
>     Parabéns Luiz! Você venceu!
>     
>     //Empate
>     O jogo terminou em empate!

9. **Tic Tac Toe:** O jogo Tic Tac Toe mostrará o seguinte tabuleiro a cada jogada realizada (linha,  coluna) alternando os jogadores. Caso seja informada uma coordenada que não obedeça as regras do jogo ou que ultrapasse o tamanho do tabuleiro, uma mensagem de erro será impressa e o jogador terá uma nova chance para jogar. Ganha quem fizer uma sequência de três primeiro símbolos primeiro, caso isso não aconteça, a partida terminará em empate.

>         1   2   3  
>     1 |   |   |   | 
>     2 |   |   |   | 
>     3 |   |   |   | 
>     ---------------
>     Luiz (X), faça sua jogada (linha e coluna): 
>     
>     //Erro
>     Movimento inválido! Tente novamente.
>        
>     //Vitória
>         1   2   3  
>     1 | X |   | X | 
>     2 | O | O | X | 
>     3 | O |   | X | 
>     ---------------
>     Parabéns Joao! Você venceu!
>     
>     //Empate
>     O jogo terminou em empate!


# Principais Desafios

Alguns dos desafios enfrentados no desenvolvimento deste projeto incluem:

 - **Gerenciamento da Herança:** Garantir que a classe base Game fornecesse uma estrutura suficientemente flexível para suportar a lógica variada dos diferentes jogos.
 - **Implementação da Lógica de Jogo:** Cada jogo possui regras e condições de vitória específicas, o que exigiu um cuidado especial para implementar métodos como checkWin (Tic Tac Toe)/(ConnectFour) e thereIsConnection (Reversi).
 - **Persistência de Dados:** A leitura e escrita das informações dos jogadores em arquivos foi um ponto que exigiu atenção para garantir que os dados fossem armazenados   corretamente entre as execuções do programa.
 - **Implementação dos Testes:** Pensar em todas as possíveis formas de teste do programa foi uma tarefa árdua e que requereu uma grande quantidade de tempo.
 - **Implementação das Funções Extras:** Foi particularmente difícil encontrar logicas para a contador de possíveis vitorias no ConnectFour, por exemplo.
 - **Vazamento de memória:** Foi necessário a utilização da ferramenta Valgrind para encontrar e resolver problemas relacionados ao acesso de memória de maneira indevida.

# Funcionalidades Extras

Além das funcionalidades básicas, algumas características extras foram implementadas:

 1. **Contador de Possíveis Formas de Ganhar:** No jogo ConnectFour foi criado um contador de "possíveis formas de ganhar", ele conta todas as possíveis linhas em que um jogador consegue conectar 4 peças, com seu valor sendo alterado conforme mais peças são jogadas.
 2. **Escolha de Tamanho de Tabuleiro:** No jogo ConnectFour o jogador é dada a escolha de 3 diferentes tamanhos de tabuleiro para jogar.
 3. **Contador de Peças:** No jogo Reversi foi criado um contador para as peças de ambos os jogadores, com o intuito de facilitar o entendimento de quem esta ganhando a partida.
 4. **Tic Tac Toe:** Também foi criado um terceiro jogo extra, o clássico Tic Tac Toe ou como é conhecido no Brasil, Jogo da Velha.
