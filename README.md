# 🌐 **Get Next Line**: Leitura de linhas de arquivos em C

## 📋 Descrição

O **Get Next Line** é uma função que lê uma linha de um arquivo ou fluxo de entrada (como stdin) até um caractere de nova linha (`\n`). A função é útil quando você precisa ler arquivos linha por linha de maneira eficiente sem carregar o arquivo inteiro na memória.

### 🚀 Funcionalidades:
- Lê o arquivo linha por linha até encontrar um caractere de nova linha.
- Trabalha com buffers para otimizar o uso da memória.
- Funciona com qualquer tipo de arquivo ou fluxo de entrada, como `stdin` ou arquivos locais.
- Permite a leitura em blocos de um arquivo até que uma linha completa seja recebida.

---

## 🧰 Funções Implementadas

Aqui estão as funções implementadas no projeto **Get Next Line**:

- **`get_next_line(int fd)`**: Lê a próxima linha do arquivo (ou fluxo de entrada).
- **`return_line(char **buffer)`**: Retorna a linha completa presente no buffer.
- **`ft_next(char *buffer)`**: Atualiza o buffer para o próximo bloco de texto após a linha atual.
- **`read_buffer(int fd, char *buffer)`**: Lê um bloco de dados do arquivo para o buffer.
- **`read_line(char *buffer)`**: Lê até encontrar um caractere de nova linha ou fim de arquivo.
- **`free_buffer(char *buffer)`**: Libera o espaço alocado para o buffer.
- **`ft_strlen(char *s)`**: Calcula o comprimento de uma string.
- **`ft_calloc(size_t n, size_t size)`**: Aloca memória e inicializa com zeros.
- **`ft_strchr(char *s, int c)`**: Encontra a primeira ocorrência de um caractere em uma string.
- **`ft_strjoin(char *s1, char *s2)`**: Concatena duas strings.
- **`ft_strdup(char *s)`**: Cria uma cópia de uma string.

---

## 🚀 Como Usar

### 1. **Clone o repositório:**

```bash
git clone https://github.com/kpierroti/get_next_line.git
cd get_next_line
```

### **2. Compilação:**
Para compilar o projeto, basta usar o make para criar o arquivo de objetos e a biblioteca estática.

```bash
make
```
Para limpar os arquivos temporários (objetos compilados), use:

```bash
make clean
```
Se você quiser limpar completamente o projeto (remover a biblioteca compilada também), use:

```bash
make fclean
```
E para recompilar tudo novamente:

```bash
make re
```

### **3. Exemplo de Uso:**
Aqui está um exemplo simples de como usar a função get_next_line:

```c
#include "get_next_line.h"
#include <fcntl.h>

int main() {
    int fd = open("example.txt", O_RDONLY);
    char *line;

    if (fd == -1) {
        return 1; // Erro ao abrir o arquivo
    }

    while ((line = get_next_line(fd)) != NULL) {
        printf("Linha: %s", line); // Imprime a linha lida
        free(line); // Não esquecer de liberar a memória!
    }

    close(fd);
    return 0;
}
```

**Saída esperada (se o arquivo example.txt contiver as seguintes linhas):**

```bash
Linha: Olá, Mundo!
Linha: Este é um exemplo.
Linha: Da função Get Next Line.
```

### **🧠 Como Funciona?**
A função Get Next Line lê um arquivo ou fluxo de entrada linha por linha. A leitura é feita em blocos, usando um buffer de tamanho fixo, até que uma linha completa seja encontrada. Quando a função é chamada, ela retorna a próxima linha disponível, até que o fim do arquivo (EOF) seja alcançado.

O fluxo de leitura funciona da seguinte forma:
1. A função lê o arquivo em blocos de tamanho fixo.
2. Quando encontra um caractere de nova linha (\n), ela retorna a linha completa.
3. Se o buffer não contém uma linha completa, a função continuará a leitura até que a linha seja completada ou o fim do arquivo seja atingido.

### **⚙️ Como Contribuir**
Se você gostaria de melhorar este projeto ou adicionar novos recursos, sinta-se à vontade para abrir uma issue ou pull request. As contribuições são sempre bem-vindas! 🚀

1. Fork o repositório.
2. Crie uma branch para a sua feature (git checkout -b feature/nova-funcionalidade).
3. Faça commit das suas mudanças (git commit -am 'Adicionando nova funcionalidade').
4. Envie para o repositório remoto (git push origin feature/nova-funcionalidade).
5. Abra uma Pull Request.

### **🔗 Licença**
Este projeto está licenciado sob a MIT License. Veja o arquivo LICENSE para mais detalhes.

### **🤖 Autor**
Criado por kpierroti.
