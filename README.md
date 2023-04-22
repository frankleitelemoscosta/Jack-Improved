<h1>Jack_Sparrow_Tunado</h1>

<img src="image/icons8-c-programming-48.png" alt="" style="width: 5%"><br>

<h2>O PROBLEMA</h2>

<p style = "text-align = justify">
Neste projeto deve se encontrar resolução para a seguinte situação: Um garoto está perdido em um labirinto, ande de forma aleatória pelas casas de matrizes(estas representam o labirinto) com um garoto até consumir tudo que é possível, ou até que ele morra tentando pegar tudo, não importa se no resultado final o garoto sobreviveu ou não.
</p>

<h2>LÓGICA UTILIZADA</h2>

<p style = "text-align = justify">
Para resolver o problema foi necessário trazer soluções para os seguintes problemas:
</p>

<ul>
    <li>Como trabalhar os dados de entrada, sendo eles um grande número de matrizes e de ordem muito grande?
    <li>Como andar pelas matrizes de maneira aleatória, e ao mesmo tempo contar as casas percorridas, alem da quantidade de elementos coletados pelo percurso ?
    <li>Como saber ao final do programa quais casas não foram acessadas?.
</ul>

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
Agora o que tem de ser feito para conseguir trabalhar a matriz e altera-la do estado original quando foi inserida no programa, alcançando a morte de Jack ou zerando todas as matrizes ?
</p>

<p style = "text-align = justify">
Para realizar tal procedimento e para que o programa se tornasse um pouco mais leve em todo o código e ainda fosse possível manipular os mesmos dados em diferentes arquivos, a matriz utilizada foi passada como referência para as funções que fosse necessário realizar alguma operação com a mesma, visto que essa matriz é acessada em vários pontos do código e em varios arquivos.
</p>


<img src="image/miranha-e-a-ram.png" alt="" style="width: 50%">

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
Inicialmente foi utilizado o srand com a semente "time(0)", o qual recupera o tempo atual em segundos desde a época de 1º de janeiro de 1970 e é usado como valor inicial, com o intervalo de 0 a 1 e uma segunda decisão aleatória era tomada para decidir se o 1 seria negativo ou não, porem essa estratégia se mostrou pouco eficiente. 
</p>

<p style = "text-align = justify">
Em uma segunda abordagem resolvi utilizar uma estratégia similar a utilizada por Michel pires em seu <a href="https://github.com/mpiress/GenerateDataToMaze">algoritmo de geração aleatória de matrizes</a>, onde ele usa um intervalo maior para decidir entre três opções de elementos para compor uma casa de uma matrix, mas o que trouxe para esse projeto foi a ideia de ter um intervalo maior, dando um campo de escolha maior para que se tornassem maiores as possibilidades de cair em 1, 0 ou -1, o pseudocódigo a seguir mostra isso:
</p>

<p>Escolha aleatória para caminhamento em uma matrix<br>
1&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;IF&nbsp;&nbsp;parameter&nbsp;&nbsp;==&nbsp;&nbsp;true&nbsp;&nbsp;THEN<br>
2&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;number_Colunm&nbsp;&nbsp;=&nbsp;&nbsp;RANDOM(0,6)<br>
3&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;number_Row&nbsp;&nbsp;=&nbsp;&nbsp;RANDOM(0,6)<br>
4&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ELSE<br>
5&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;choosen&nbsp;&nbsp;=&nbsp;&nbsp;RANDOM(0,19)<br>
6&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;IF choosen&nbsp;&nbsp;>&nbsp;&nbsp;5&nbsp;&nbsp;AND&nbsp;&nbsp;choosen&nbsp;&nbsp;<&nbsp;&nbsp;12&nbsp;&nbsp;THEN<br>
7&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;number_Colunm = 1<br>
8&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ELSE&nbsp;&nbsp;IF&nbsp;&nbsp;choosen&nbsp;&nbsp;>&nbsp;&nbsp;0&nbsp;&nbsp;AND&nbsp;&nbsp;choosen&nbsp;&nbsp;<&nbsp;&nbsp;6&nbsp;&nbsp;THEN<br>
9&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;number_Colunm&nbsp;&nbsp;=&nbsp;&nbsp;-1<br>
10&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ELSE<br>
11&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;number_Colunm&nbsp;&nbsp;=&nbsp;&nbsp;0<br>
12&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;choosen&nbsp;&nbsp;=&nbsp;&nbsp;RANDOM(0,19)<br>
13&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;IF choosen&nbsp;&nbsp;>&nbsp;&nbsp;5&nbsp;&nbsp;AND&nbsp;&nbsp;choosen&nbsp;&nbsp;<&nbsp;&nbsp;12&nbsp;&nbsp;THEN<br>
14&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;number_Row&nbsp;&nbsp;=&nbsp;&nbsp;1<br>
15&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ELSE&nbsp;&nbsp;IF&nbsp;&nbsp;choosen&nbsp;&nbsp;>&nbsp;&nbsp;0&nbsp;&nbsp;AND&nbsp;&nbsp;choosen&nbsp;&nbsp;<&nbsp;&nbsp;6&nbsp;&nbsp;THEN<br>
16&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;number_Row&nbsp;&nbsp;=&nbsp;&nbsp;-1<br>
17&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ELSE<br>
18&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;number_Row&nbsp;&nbsp;=&nbsp;&nbsp;0<br>
19&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;END&nbsp;&nbsp;IF<br></p>

<p style = "text-align = justify">
O primeiro if demonstra uma regra que foi estabelecida para que Jack conseguisse percorrer todas as matrizes sem ficar preso a necessidade de ter de zerar a corrente matriz onde ele está, então a regra é: quando ele chega as extremidades de uma matriz ele é teletransportado para outra matriz do arquivo de entrada, e uma posição da matriz é escolhida de forma aleatória.Como mostra a imagem:
<p>

<img src="image/LOGICA-DE-TELETRANSPORTE.png" alt="" style="width: 70% ">

<p style = "text-align = justify">
Determinado a forma de caminhamento pela matriz foi necessário saber por onde Jack não estava passando assim que o programa encerrasse, para tal conceituemos o seguinte, toda matriz tem linhas e colunas atreladas a uma de suas casas, e suas linhas e colunas estão em ordem crescente, como mostra a imagem:
</p>

<img src="image/matriz-e-suas-linhas-e-colunas.png" alt="" style="width: 40% ">

<p style = "text-align = justify">
Agora se enumerarmos em ordem crescente as casas da matriz, considerando-a quadratica, e seguindo o sentido das colunas variando de um a um, e pulando uma linha quando chegarmos no valor da ordem ao variar as colunas, e com isso retornar ao primeiro elemento da linha subsequente e prosseguir a contage até chegar a ultima casa da matriz, que fica na quina inferior direita, teremos a seguinte situação: cada casa vai ter uma posição em uma contagem em ordem crescente, e considerando uma ordem n, teremos o tamanho dessa contagem que é: n².
</p>

<p style = "text-align = justify">
Se colocassemos todos os elementos da matriz um após o outro sem quebrarmos uma linha durante essa organização o que teriamos é um vetor de n² posições, supondo que seja uma matriz de ordem 7 temos:
</p>

<img src="image/vetor(1).jpg" alt="" style="width: 40% ">

<p style = "text-align = justify">
Estas posições são os elementos da matriz e podem ser encontrados com a seguinte função de duas variaveis reais: Elemento = ((Linha x Ordem) + 1) + Coluna, mas observe que a fórmula esta declarada no contexto de indexação da computação, ou seja, o primeiro index de um vetor não será 1 e sim 0, agora imagine uma matriz de ordem 3 você quer descobrir um elemento cuja linha de localização é de valor 2, e coluna de valor 1, se você multiplicar o valor da linha pela ordem obterá o ultimo elemento da linha anterior, 2 x 3 = 6, se somarmos 1 a esse resultado obteremos o primeiro elemento da linha onde o elemento procurado esta, e somando ao valor da coluna teremos o elemento procurado, 2 x 3 + 1 + 1 = 8.
</p>

<img src="image/prova.png" alt="" style="width: 40% ">

<p style = "text-align = justify">
Agora tendo as posições extraidas a cada interação pela expressão matemática apresentada, e sendo salva na pasta Diferentvet, pode se tratar da maneira de como obter a quantidade de casas não passadas por Jack. Para tal ja que temos as posições por onde Jack passou basta obtermos a quantidade total de elementos menos a quantidade de casas onde ele passou, mas para que fosse desconsiderado as repetições as posições encontradas foram armazenadas em um vetor totalmente preenchido com zeros, onde são inseridos na posição respectiva ao seu valor, e a inserção neste vetor só ocorre se a casa do vetor estiver preenchida com zero, se não for o caso ele não entra no desvio condicional e conta o número de casas onde ele passou, supondo que o arquivo de entrada tenha 3 matrizes, e essas tenham ordem 4 o algoritmo seria:
</p>

Contagem de casas não visitadas:<br>
1&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FOR&nbsp;&nbsp;i&nbsp;&nbsp;=&nbsp;&nbsp;1&nbsp;&nbsp;TO&nbsp;&nbsp;16&nbsp;&nbsp;STEP<br>
2&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;vet_check&nbsp;&nbsp;=&nbsp;&nbsp;0<br>
3&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;END&nbsp;&nbsp;FOR<br>
4&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;WHILE&nbsp;&nbsp;Counter&nbsp;&nbsp;<=&nbsp;&nbsp;3<br>
5&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Counter++<br>
6&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SET&nbsp;&nbsp;file&nbsp;&nbsp;=&nbsp;&nbsp;OPEN("Diferentvet/output.data","r")<br>
7&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Cleararrey(name)<br>
8&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SET&nbsp;&nbsp;size&nbsp;&nbsp;=&nbsp;&nbsp;READ_INTERGER(file)<br>
9&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SET&nbsp;&nbsp;lixo&nbsp;&nbsp;=&nbsp;&nbsp;READ_INTERGER(file)<br>
10&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;vet&nbsp;&nbsp;=&nbsp;&nbsp;ALLOCATE_MEMORY(sizeof(Interger))<br>
11&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FOR&nbsp;&nbsp;i&nbsp;&nbsp;=&nbsp;&nbsp;1&nbsp;&nbsp;TO&nbsp;&nbsp;size&nbsp;&nbsp;STEP<br>
12&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SET&nbsp;&nbsp;vet[i]&nbsp;&nbsp;=&nbsp;&nbsp;READ_INTERGER(file)<br>
13&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;END&nbsp;&nbsp;FOR<br>
14&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FOR&nbsp;&nbsp;i&nbsp;&nbsp;=&nbsp;&nbsp;1&nbsp;&nbsp;TO&nbsp;&nbsp;size&nbsp;&nbsp;STEP<br>
15&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;index&nbsp;&nbsp;=&nbsp;&nbsp;vet[&nbsp;i&nbsp;]<br>
16&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;IF&nbsp;&nbsp;vet_check[&nbsp;i&nbsp;]&nbsp;&nbsp;==&nbsp;&nbsp;0&nbsp;&nbsp;THEN<br>
17&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;vet_check[index]&nbsp;&nbsp;=&nbsp;&nbsp;index<br>
18&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Counter_Walking++<br>
19&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;END&nbsp;&nbsp;IF<br>
20&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;END&nbsp;&nbsp;FOR<br>
21&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FOR&nbsp;&nbsp;i&nbsp;&nbsp;=&nbsp;&nbsp;1&nbsp;&nbsp;TO&nbsp;&nbsp;16&nbsp;&nbsp;STEP<br>
22&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;vet_check[&nbsp;i&nbsp;]&nbsp;&nbsp;=&nbsp;&nbsp;0<br>
23&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;END&nbsp;&nbsp;FOR<br>
24&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;QuantitiHouses&nbsp;&nbsp;=&nbsp;&nbsp;tamanho_vet&nbsp;&nbsp;-&nbsp;&nbsp;Counter_Walking<br>

<h2>EXEMPLO DE ENTRADA E SAÍDA</h2>

<p style = "text-align = justify">

</p>

<h2>COMO COMPILAR ESSE PROJETO</h2>

![](https://user-images.githubusercontent.com/107070061/226108916-b37c30be-d111-4ec2-9d4a-1e01bd3901ed.gif)

<p style = "text-align = justify">
Como mostra o gif, neste projeto é utilizado o arquivo de diretrizes de comando makefile, para compilar e executar este projeto basta digitar os seguintes comandos no terminal:
</p>

<ul>
    <li>make ou make all
    <li>make run
</ul>

<p style = "text-align = justify">
o primeiro comando ao ser executado no terminal pede ao sistema operacional que procure um arquivos dentro da pasta do projeto chamado de Makefile, e assim que encontra como não houve mais nenhuma especificação após ser digitado make ele vai procurar por uma diretriz dentro deste arquivo chamada de all, e executará o comando redigido no campo desta diretriz, na mesma lógica temos o comando make run, porem este comando esta codificado para executar uma diretriz que fará a execução do executável gerado no processo de compilação. E ainda há uma outra diretriz cujo nome é: makeclean, que realiza a limpeza do executável.
</p>

<h2>CONCLUSÃO</h2>
<p style = "text-align = justify">
Pode se concluir a partir de todas as informações aqui discorridas, e das soluções as problemáticas apontadas que representam a estruturação do código, que não se faz possível estipular um custo preciso a este algoritmo, visto que a forma de caminhamento pela matriz é indefinida, a cada interação não há como prever com exatidão o que vai acontecer, sendo assim é complexo elaborar um custo computacional, Segundo <a href = "https://pt.wikipedia.org/wiki/Nivio_Ziviani">Nivio Ziviane</a> a abordagem mais adequada para análise de algoritmos está relacionada a entrada, e análise das operações realizadas com esses dados, porem é muito usual desconsiderar operações aritméticas e considerar apenas laços de repetição e desvios condicionais, mas no cenário destre projeto não é possível dizer quantas vezes a entrada vai interagir nos laços de repetições ou quantas vezes a execução sofrerá um desvio condicional e executará outro bloco de código influenciando no tempo de execução.
</p>
<h2>REFERÊNCIAS</h2>

<ul>
    <li>TH.Cormen,Algoritmos: Teoria e Prática, MIT press,2009, Pag: 7 e 8.
    <li>N.Ziviane,Projeto de Algoritmos: com implementação em Java e C++,São Paulo,Thonson Learning,2007.
</ul>

<h2>AUTOR</h2>

Frank Leite Lemos Costa, aluno de Engenharia da Computação no <a href = "https://www.cefetmg.br/">CEFET</a>, 3° período.

<a href="https://www.linkedin.com/in/frank-leite-6a6a84198/"><img src="image/linkedin.png" alt="" style="width: 10% "></a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<img src="image/whatsapp.png" alt="" style="width: 20% "><br>&nbsp;&nbsp;&nbsp;linkedin&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(31) 99644-9587