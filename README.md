<h1>Jack_Sparrow_Tunado</h1>

<img src="image/icons8-c-programming-48.png" alt="" style="width: 5%"><br>

<h2>O PROBLEMA</h2>

<p style = "text-align = justify">
Neste projeto deve se encontrar resolução para a seguinte situação: Um garoto está perdido em um labirinto, ande de forma aleatória pelas casas de matrizes(estas representam o labirinto) com um garoto até consumir tudo que é possível, ou até que ele morra tentando pegar tudo, não importa se no resultado final o garoto sobreviveu ou não.
</p>

<h2>LÓGICA UTILIZADA</h2>

<p style = "text-align = justify">
Para preencher os arquivos foi utilizado o <a href="https://github.com/mpiress/GenerateDataToMaze">algoritimo</a> desenvolvido por Michel Pires, que esta em seu perfil do git hub.  
</p>

<p style = "text-align = justify">
Se faz necessário abrir o arquivo, ler e operar matriz por matriz, mas e se houver uma quantidade de matrizes tão grande que não seja possível comportar a quantidade de dados na memória RAM de uma só vez, o que fazer diante disso?
</p>

<p style = "text-align = justify">
As matrizes foram gravadas em arquivos distintos, para que fosse possível extrair uma matriz de cada vez, e colocar apenas uma na mémoria RAM para ser trabalhada.
</p>

<img src="image/harrdware.png" alt="" style="width: 50%">

<p style = "text-align = justify">
A RAM opera em velocidades muito mais altas em comparação com HDDs ou SSDs, pois está diretamente conectada à CPU (Central Processing Unit) do computador e fornece acesso rápido aos dados que a CPU precisa para executar tarefas. Isso permite que a CPU recupere e armazene rapidamente dados de e para a RAM, o que ajuda a acelerar o desempenho geral de um computador.
</p>

<p style = "text-align = justify">
Porem ela é limitada, e lembrando que existem diversos outros processos sendo executados na CPU e armazenados na RAM, sendo assim para ganhar eficiência neste projeto em qualquer computador é inteligente trabalhar com os dados de uma matriz de cada vez., assim otimizando espaço. 
</p>

<p style = "text-align = justify">
Agora o que tem de ser feito para conseguir trabalhar a matriz e altera-la do estado original quando foi inserida no programa, alcançando o ?
</p>

<p style = "text-align = justify">
Para realizar tal procedimento e para que o programa se tornasse um pouco mais leve em todo o código e ainda fosse possível manipular os mesmos dados em diferentes arquivos, a matriz utilizada foi passada como referência para as funções que fosse necessário realizar alguma operação com a mesma, visto que essa matriz é acessada em vários pontos do código e em varios arquivos.
</p>


<img src="image/Meme-Homem-Aranha-No-Way-Home.jpg" alt="" style="width: 50%">

<p style = "text-align = justify">
O ponteiro é uma variável que aponta a uma posição de memória, enquanto uma variável armazena uma posição e o conteúdo armazenado nessa variável, mostrando se mais caro computacionalmente, isso é dito pois a refencia passada da matriz nesse projeto se trata de um ponteiro.
</p>

<p style = "text-align = justify">
Resolvido a forma de manter os dados em uma estrutura que permitisse desenvolve-los, surge a questão: como caminhar pela matriz de maneira a decidir os passos de forma aleatória?.
</p>

<p style = "text-align = justify">
Para caminhar pela matriz foi utilizado um processo de escolha aleatória e imparcial nativo da linguage C, a qual pode ser chamada utilizando a seguinte expressão "srand()", que se trata de um gerador de números, uma função interna dos arquivos da linguagem, que executa o procedimento de gerar números aleatórios de acordo com uma semente fornecida.
</p>

<p style = "text-align = justify">
Inicialmente foi utilizado o srand com a semente "time(0)" recupera o tempo atual em segundos desde a época de 1º de janeiro de 1970 e é usado como valor inicial, com o intervalo de 0 a 1 e uma segunda decisão aleatória era tomada para decidir se o 1 seria negativo ou não, porem essa estratégia se mostrou pouco eficiente. 
</p>

<h2>CONCLUSÃO</h2>

<h2>REFERÊNCIAS</h2>

<ul>
    <li>ChatGPT.
    <li>TH.Cormen,Algoritmos: Teoria e Prática, MIT press,2009, Pag: 7 e 8.
</ul>

<h2>AUTOR</h2>

Frank Leite Lemos Costa, aluno de Engenharia da Computação no 3° período.

<a href="https://www.linkedin.com/in/frank-leite-6a6a84198/"><img src="image/linkedin.png" alt="" style="width: 10% "><br>linkedin</a>

<img src="image/whatsapp.png" alt="" style="width: 20% "><br> (31) 99644-9587