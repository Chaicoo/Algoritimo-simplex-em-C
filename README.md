# Algoritimo simplex em C
<div align="justify">
<p>Trabalho realizado para a disciplina de Programação Linear. O algoritimo calcula PPL's a partir da entrada com o tableau do simplex na forma padrão, o número de variáveis e de restrições. Ele é capaz de calcular soluções únicas e ilimitadas, os PPL's de solução multiplas só são calculados pelo problema se o tableau inserido for o inicial.</p>
 </div>

<hr>

## Funcionamento do código:
- Função escolher_Entrada():
  <p>A funçao percorre a tabela até encontrar o menor valor negativo, quando o encontra ele se torna o pivo e sua coluca é armazenada na variável coluna_Pivo.</p>
  <div align="center">
    <img height="320em" src="https://github.com/Chaicoo/Algoritimo-simplex-em-C/blob/main/img/escolher-entrada.jpeg"/>
  </div>
- Função escolher_Pivo():
  <p>A funçao divide os valores da coluna B do tableau pelos da coluna_Pivo, a menor razão positiva define qual será o pivo.</p>
  <div align="center">
    <img height="320em" src="https://github.com/Chaicoo/Algoritimo-simplex-em-C/blob/main/img/escolher-pivo.jpeg"/>
  </div>
- Função gerar_Linha_Pivo():
  <p>A funçao divide os elementos da linha do pivo pelo pivo, gerando assim a nova linha pivo, após isso será chamada a função gerar_Novas_Linhas().</p>
  <div align="center">
    <img height="320em" src="https://github.com/Chaicoo/Algoritimo-simplex-em-C/blob/main/img/gerar-linha-pivo.jpeg"/>
  </div>
- Função gerar_Novas_Linhas():
  <p>A funçao usa a linha_Pivo para gerar as novas linhas: multiplica-se a linha pivo pelo elemento na coluna pivo da respectiva linha, sendo que usa-se o inverso desse elemento, ou seja ele multiplicado por (-1).</p>
  <div align="center">
    <img height="320em" src="https://github.com/Chaicoo/Algoritimo-simplex-em-C/blob/main/img/gerar-novas-linhas.jpeg"/>
  </div>
- Função simplex():
  <p>A funçao irá fazer a chamada das demais funções mencionadas anteriormente e irá por fim exibir a nova tabela pós método.</p>
  <div align="center">
    <img height="320em" src="https://github.com/Chaicoo/Algoritimo-simplex-em-C/blob/main/img/metodo-simplex.jpeg"/>
  </div>
- Função testar_Solucao():
  <p align="justify">A funçao irá percorrer a linha da Função Objetivo, caso exista algum número negativo nela, a funçao irá definir que ela a solução ainda não é otima, e irá reiniciar o méto a partir da tabela atual. A função irá fazer a chamada da função testar_Ilimitado, pois caso o PPL seja ilimitado na main não será testado se a solução é otima ou não, pois ela é ilimitada./p>
  <div align="center">
    <img height="320em" src="https://github.com/Chaicoo/Algoritimo-simplex-em-C/blob/main/img/testar-solucao.jpeg"/>
  </div>
- Função testar_Ilimitado():
  <p>A funçao divide todos os elementos da coluca pivo pelos elementos da coluna B do tableau, se as razões forem negativas então a função retorna que o PPl é ilimitado.</p>
  <div align="center">
    <img height="320em" src="https://github.com/Chaicoo/Algoritimo-simplex-em-C/blob/main/img/testar-ilimitado.jpeg"/>
  </div>
- Função testar_Multi():
  <p>A funçao difide os elemento da linha da Função Objetivo pelas demasi linhas da tabela, se as razões forem iguais então o PPL é multiplo. Essa função só funciona para caso o tableu inserido for o original.</p>  
  <div align="center">
    <img height="420em" src="https://github.com/Chaicoo/Algoritimo-simplex-em-C/blob/main/img/testar-multi.jpeg"/>
  </div>
- Função calcular_Variaveis():
  <p>A funçao irá funcionar em duas etapas, a primeira ela busca as variáveis básicas, ela decide quais são básicas avaliando a soma da sua coluna, casa a soma for 1 então a variável é básica. A segunda etapa define o valor das variáveis que previamente foram definidas como básicas, a função irá avaliar a coluna B nas linhas em que o valor da dita variável for 1.</p>    
  <div align="center">
    <img height="420em" src="https://github.com/Chaicoo/Algoritimo-simplex-em-C/blob/main/img/calcular-variaveis.jpeg"/>
  </div>
- Função main():
  <p>A funçao organiza a entrada dos dados e as chamadas das demais funções. Primeiro é chamada a função testar_Multi, e é usado um while que irá repetir a chamada da função testar_Solucao enquanto não for encontrado solucão otima, a menos que seja ilimitada, nesse caso o programa encerra e retorna que o PPl é ilimitado, no caso de ser multipli o programa apenas exibe o valor gerado pela Função Objetivo.</p>    
  <div align="center">
    <img height="520em" src="https://github.com/Chaicoo/Algoritimo-simplex-em-C/blob/main/img/main.jpeg"/>
  </div>
