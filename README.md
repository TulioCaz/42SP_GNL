# Get Next Line

Get_next_line (42São Paulo) 2021. Este projeto consiste basicamente em uma função que lê um arquivo linha por linha.

*Observação: Existem muitos métodos mais fáceis de fazer isso usando funções C padrão. Mas o objetivo aqui é poder fazer isso usando apenas as funções padrão `read`, `malloc` e `free`.*

## Manual

```c
int get_next_line(int fd, char **line);
```

A função lê um arquivo aberto descrito pelo file descriptor `fd`, retornando linha por linha cada vez que é chamada dentro do parâmetro `line`.

**Return:** -1 se houver um erro; 0 se chegar ao final do arquivo. 1 se tiver sucesso na leitura.

## Aprendizado

Depois de terminar este projeto, você definitivamente aprenderá um pouco mais sobre variáveis estáticas, ponteiros, arrays, listas vinculadas (se você decidir fazer a parte bônus), alocação de memória dinâmica e manipulação de arquivos.
