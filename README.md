<h1 align="center">TiMath</h1>

<p align="center">
  <img src="https://img.shields.io/github/repo-size/brunoribeirol/jogoAED?style=flat" alt="Repository Size" />
  <img src="https://img.shields.io/github/commit-activity/t/brunoribeirol/jogoAED?style=flat&logo=github" alt="Commit Activity" />
  <a href="LICENSE.md"><img src="https://img.shields.io/github/license/brunoribeirol/jogoAED?style" alt="License" /></a>
</p>

O TiMath é um jogo desenvolvido em C, onde o jogador precisa responder 10 expressões matemáticas no menor tempo possível. Os números e as operações são gerados aleatoriamente no início do programa e armazenados em uma lista encadeada. O jogador só consegue avançar quando responder a expressão corretamente porque a próxima operação sempre utiliza o resultado da expressão anterior. O jogo vai ficando mais difícil de acordo com o avanço do jogador, ou seja, as expressões vão ficando maiores e mais complicadas.

Referência: "Pequenos Gênios" - Domingão com o Huck

## Funcionalidades

- **Jogar TiMath:** Função principal do jogo. Utilize os números do seu teclado para responder as expressões e o enter para inserir sua resposta
- **Visualizar Ranking:** Visualizar o ranking dos jogadores com base em suas pontuações
- **Sair:** Encerra o programa

## Instruções de Compilação e Execução:

```sh
gcc ./src/*.c -I./include -o jogoAED
```

Seguido por

```sh
./jogoAED
```

Ou simplesmente

```sh
make run
```

## Regras do Jogo

- Responder corretamente aa expressões matemáticas no menor tempo que conseguir
- O jogo termina quando o jogador responde todas as expressões
  corretamente
- A pontuação é baseada no tempo em que o jogador responde todas as
  expressões

## Arquivo de Pontuação

As pontuações dos jogadores são salvas no arquivo
`ranking.txt`. Cada linha do arquivo contém o nome do jogador e
sua pontuação correspondente.

## Equipe

- <a href="https://github.com/brunoribeirol">Bruno Ribeiro</a> -
  brlla@cesar.school 📩
- <a href="https://github.com/Zabbak">Lucas Kabbaz</a> - lbk@cesar.school
  📩
- <a href="https://github.com/igoralvesa">Igor Alves</a> -
  iaa@cesar.school 📩
- <a href="https://github.com/vinipetribu">Vinícius Petribu</a> -
  vclp@cesar.school 📩

## Notas Adicionais

- O código utiliza a biblioteca padrão `stdio.h`,
  `stdlib.h`, `string.h`, `unistd.h`,
  `time.h`, `stdbool.h`, `sys/time.h` e
  as bibliotecas customizadas `screen.h`,
  `keyboard.h`, `timer.h`.

  - A pontuação é salva no arquivo `ranking.txt` após cada jogo.

  - Este projeto foi desenvolvido como um exercício para prática nossa
    prática em programação na linguagem C, focando em Estruturas de Dados e
    Algoritmos de Ordenação

  - Qualquer contribuição ou sugestão é bem-vinda.

Divirta-se jogando TiMath!
