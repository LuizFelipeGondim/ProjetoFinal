Jogo de Tabuleiro em C++<br>
Visão Geral do Projeto<br>
Este projeto implementa um conjunto de jogos de tabuleiro clássicos utilizando C++, permitindo que dois jogadores se enfrentem em uma partida. Os jogos disponíveis      incluem:<br>

Tic Tac Toe (Jogo da Velha)<br>
Reversi<br>
Connect Four (LIG4)<br>

Cada jogo foi estruturado fazendo uso de  herança e polimorfismos para facilitar a reutilização de código e garantir uma fácil extensão para outros jogos futuros.<br>

Estrutura do Projeto<br>

A estrutura do projeto é modular, com classes específicas para cada jogo derivadas de uma classe base Game que por sua vez é derivada da classe player. A classe GameBoard gerencia a interface com os jogadores e controla o fluxo geral do programa.<br>
Principais Arquivos:<br>
    Player.hpp/cpp: Armazena e gerencia quaisquer dados relacionados aos jogadores.<br>
    Game.hpp/cpp: Define a classe abstrata base para os jogos, incluindo a lógica comum para todos os jogos, como a criação e impressão do tabuleiro e verificação de        preenchimento do tabuleiro.<br>
    GameBoard.hpp/cpp: Controla o registro dos jogadores, a leitura/escrita de dados dos jogadores em arquivos, e o início das partidas entre jogadores.<br>
    TicTacToe.hpp/cpp: Implementa o jogo Tic Tac Toe, incluindo a lógica para verificar vitórias e processar jogadas.<br>
    Reversi.hpp/cpp: Implementa o jogo Reversi, com métodos específicos para gerenciar as regras de captura de peças e contagem de peças no tabuleiro.<br>
    ConnectFour.hpp/cpp: Implemeta o jogo Connect Four, com metodos especificos para gerenciar as condiçoes de vitoria e jogada validas<br>


Principais Desafios<br>

Alguns dos desafios enfrentados no desenvolvimento deste projeto incluem:<br>

Gerenciamento da Herança: Garantir que a classe base Game fornecesse uma estrutura suficientemente flexível para suportar a lógica variada dos diferentes jogos.<br>
Implementação da Lógica de Jogo: Cada jogo possui regras e condições de vitória específicas, o que exigiu um cuidado especial para implementar métodos como checkWin (Tic Tac Toe)/(ConnectFour) e thereIsConnection (Reversi).<br>
Persistência de Dados: A leitura e escrita das informações dos jogadores em arquivos foi um ponto que exigiu atenção para garantir que os dados fossem armazenados   corretamente entre as execuções do programa.<br>
Implementação dos Testes: Pensar em todas as possiveis formas de teste do programa foi uma tarefa ardiosa e que requeriu uma grande quantidade de tempo.<br>
Implementação das Funçoes Extras: Foi partircularmente dificil encontrar logicas para a contador de possiveis vitorias no Connectfour.<br>

Funcionalidades Extras<br>

Além das funcionalidades básicas, algumas características extras foram implementadas:<br>

Contador de Possiveis Formas de Ganhar: No jogo ConnectFour foi criado um contador de "possiveis formas de ganhar", ele conta todas as possiveis linhas em que um jogador consegue conectar 4 peças, com seu valor sendo alterado conforme mais peças são jogadas.<br>
Escolha de Tamanho de Tabuleiro: No jogo ConnectFour o jogador é dada a escolha de 3 diferentes tamanhos de tabuleiro para jogar.<br>
Contador de Peças: No jogo Reversi foi criado um contador para as peças de ambos os jogadores, com o intuito de facilitar o entendimento de quem esta ganhando a partida.<br>
Tic Tac Toe: Também foi criado um terceiro jogo extra, o classico Tic Tac Toe ou como é conhecido no Brasil, Jogo da Velha.<br>
    

    
    
