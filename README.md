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
  <div align="center">
    <p>A funçao</p>
    <img height="320em" src="https://github.com/Chaicoo/Algoritimo-simplex-em-C/blob/main/img/testar-solucao.jpeg"/>
  </div>
- Função testar_Ilimitado():
  <div align="center">
    <p>A funçao</p>
    <img height="320em" src="https://github.com/Chaicoo/Algoritimo-simplex-em-C/blob/main/img/testar-ilimitado.jpeg"/>
  </div>
- Função testar_Multi():
  <div align="center">
    <p>A funçao</p>
    <img height="420em" src="https://github.com/Chaicoo/Algoritimo-simplex-em-C/blob/main/img/testar-multi.jpeg"/>
  </div>
- Função calcular_Variaveis():
  <div align="center">
    <p>A funçao</p>
    <img height="420em" src="https://github.com/Chaicoo/Algoritimo-simplex-em-C/blob/main/img/calcular-variaveis.jpeg"/>
  </div>
- Função main():
  <div align="center">
    <p>A funçao</p>
    <img height="520em" src="https://github.com/Chaicoo/Algoritimo-simplex-em-C/blob/main/img/main.jpeg"/>
  </div>
