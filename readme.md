# 42 Labs 4º Edição - Compressor de dados
Projeto com o intuito de criação de um programa para compressão e outro para descompressão de dados usando o algoritmo de Huffman.

## Sumário

- [Conceitos aplicados](#conceitos-aplicados)
  - [Algoritmo de Huffman](#algoritmo-de-compressão-de-huffman)
  - [Memória compartilhada](#memória-compartilhada)
- [Setup](#setup)
- [Considerações finais](#considerações-finais)

### Principais Conceitos aplicados

- Memória Compartilhada
- Árvore Binária
- Algoritmo de Huffman

#### Algoritmo de Compressão de Huffman
A codificação de Huffman é um método de compressão que usa as probabilidades de ocorrência dos símbolos no conjunto de dados a ser comprimido para determinar códigos de tamanho variável para cada símbolo.

##### Árvore Binária usando a palavra "Hello"

![img](https://uploaddeimagens.com.br/images/004/299/926/original/Screenshot_2023-01-15_150528.png?1673805940)

Dentro do projeto, o algoritmo cria uma árvore binária usando uma tabela com a frequência de ocorrência de cada caractere. Com a árvore binária, podemos criar um dicionário com o código binário comprimido de cada caractere. A operação inversa é simples, usando o código binário criado anteriormente e verificando no dicionário construído conseguimos obter o caractere original.

#### Memória compartilhada
Em computação, memória compartilhada é uma memória que pode ser acessada simultaneamente por múltiplos programas com a intenção de prover comunicação entre eles ou para evitar cópias redundantes.

No projeto, a memória compartilhada é a forma de comunicação entre o decoder e o encoder, passando informação essenciais como: tabela de frequência, binário do texto completo e o tamanho do texto binário (usado para alocação dinâmica).

### Setup
Para a execução do programa é necessário ter o compilador GCC e o programa make para a compilação dos programas.
 
```bash
  $ make
```
use o programa encoder com um arquivo de texto para a compressão de dados
  
```bash
  $ ./encoder <caminho para o arquivo de texto>
```
Após a execução do encoder, execute o programa decoder para a descompressão dos dados
```bash
  $ ./decoder
```
### Considerações finais
O projeto foi muito interessando do início ao fim, muitos conceitos novos e consolidação de novo. Para mim, aprender a criar listas encadeadas e funções recursivas foi incrível, aprender sobre árvores binárias e memória compartilhada foi bem trabalho, mas muito recompensador. Adorei fazer o projeto e aprendi muito, uma experiência incrível e muito engrandecedora.
