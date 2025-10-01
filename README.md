# 🔄 Push_swap

[![42 School](https://img.shields.io/badge/42-Porto-blue)](https://www.42porto.com/)
[![C](https://img.shields.io/badge/C-99-blue.svg)](https://en.wikipedia.org/wiki/C99)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

Um projeto da **42 School** que implementa um algoritmo eficiente de ordenação usando duas pilhas e um conjunto limitado de operações.

## 📋 Índice

- [Sobre o Projeto](#sobre-o-projeto)
- [Regras do Jogo](#regras-do-jogo)
- [Operações Permitidas](#operações-permitidas)
- [Algoritmo](#algoritmo)
- [Compilação](#compilação)
- [Uso](#uso)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Exemplos](#exemplos)
- [Avaliação](#avaliação)
- [Autor](#autor)

## 📖 Sobre o Projeto

**Push_swap** é um projeto da 42 School que desafia os estudantes a criar um programa que ordena números inteiros usando duas pilhas (A e B) e um conjunto específico de operações. O objetivo é ordenar a pilha A em ordem crescente com o menor número possível de operações.

### 🎯 Objetivos

- Implementar algoritmos de ordenação eficientes
- Otimizar o número de operações necessárias
- Trabalhar com estruturas de dados (pilhas/listas circulares)
- Gerenciar memória adequadamente
- Lidar com validação de entrada e tratamento de erros

## 🎮 Regras do Jogo

1. Você tem duas pilhas: **A** e **B**
2. A pilha **A** contém números inteiros aleatórios (positivos e/ou negativos)
3. A pilha **B** está vazia no início
4. O objetivo é ordenar a pilha **A** em ordem crescente
5. Você pode usar apenas as operações permitidas

## ⚙️ Operações Permitidas

### Operações em uma pilha:
- `sa` - Swap A: Troca os dois primeiros elementos da pilha A
- `sb` - Swap B: Troca os dois primeiros elementos da pilha B
- `ss` - Swap A e B simultaneamente

### Operações de rotação:
- `ra` - Rotate A: Move todos os elementos da pilha A uma posição para cima
- `rb` - Rotate B: Move todos os elementos da pilha B uma posição para cima
- `rr` - Rotate A e B simultaneamente
- `rra` - Reverse Rotate A: Move todos os elementos da pilha A uma posição para baixo
- `rrb` - Reverse Rotate B: Move todos os elementos da pilha B uma posição para baixo
- `rrr` - Reverse Rotate A e B simultaneamente

### Operações de transferência:
- `pa` - Push A: Move o primeiro elemento da pilha B para o topo da pilha A
- `pb` - Push B: Move o primeiro elemento da pilha A para o topo da pilha B

## 🧠 Algoritmo

O projeto implementa diferentes estratégias de ordenação dependendo do tamanho da entrada:

### Para 3 elementos ou menos:
- Algoritmo específico otimizado para casos pequenos

### Para mais de 3 elementos:
1. **Análise de custos**: Calcula o custo de mover cada elemento para sua posição correta
2. **Identificação do elemento mais barato**: Escolhe o elemento que requer menos operações
3. **Posicionamento estratégico**: Move elementos entre as pilhas de forma otimizada
4. **Finalização**: Retorna todos os elementos para a pilha A ordenados

### Características do algoritmo:
- ✅ Complexidade otimizada para diferentes tamanhos de entrada
- ✅ Uso de listas circulares duplamente ligadas
- ✅ Cálculo de mediana para estratégias de rotação
- ✅ Sistema de custos para escolha ótima de movimentos

## 🔨 Compilação

### Pré-requisitos
- Compilador GCC ou Clang
- Make
- Sistema Unix/Linux (testado no Ubuntu)

### Compilar o projeto:
```bash
make
```

### Outros comandos úteis:
```bash
make clean    # Remove arquivos objeto
make fclean   # Remove arquivos objeto e executável
make re       # Recompila tudo do zero
```

## 🚀 Uso

### Sintaxe básica:
```bash
./push_swap [números separados por espaço]
```

### Exemplos:
```bash
# Ordenar 5 números
./push_swap 3 1 4 1 5

# Ordenar números negativos e positivos
./push_swap -2 0 5 -8 3

# Usar com string (números entre aspas)
./push_swap "3 1 4 1 5"
```

### Verificar resultado com checker:
```bash
# Gerar operações e verificar se estão corretas
./push_swap 3 1 4 | ./checker_linux 3 1 4
```

### Contar número de operações:
```bash
./push_swap 3 1 4 | wc -l
```

## 📁 Estrutura do Projeto

```
.
├── Makefile                 # Arquivo de compilação
├── push_swap.h             # Header principal
├── main.c                  # Função principal
├── t_stack.c              # Operações básicas da pilha
├── command.c              # Comandos base (swap, push, rotate)
├── command_a.c            # Comandos específicos da pilha A
├── command_b.c            # Comandos específicos da pilha B
├── command_ab.c           # Comandos simultâneos
├── utils.c                # Funções utilitárias
├── utils_sort.c           # Utilitários de ordenação
├── utils_sort_a.c         # Utilitários específicos da pilha A
├── big_sort.c             # Algoritmo principal de ordenação
├── checker_linux          # Programa para verificar resultado
└── libft/                 # Biblioteca personalizada
    ├── libft.h
    ├── Makefile
    └── [arquivos da libft]
```

## 📊 Exemplos

### Exemplo 1: 3 números
```bash
$ ./push_swap 3 2 1
sa
rra

$ ./push_swap 3 2 1 | wc -l
2
```

### Exemplo 2: 5 números
```bash
$ ./push_swap 5 4 3 2 1
pb
pb
ra
sa
pa
pa

$ ./push_swap 5 4 3 2 1 | wc -l
6
```

### Exemplo 3: Verificação com checker
```bash
$ ./push_swap 4 67 3 87 23 | ./checker_linux 4 67 3 87 23
OK
```

### Funcionalidades implementadas:
- ✅ Validação de entrada (números duplicados, não-numéricos)
- ✅ Gerenciamento de memória sem vazamentos
- ✅ Tratamento de erros
- ✅ Algoritmo otimizado para diferentes tamanhos
- ✅ Conformidade com a norma da 42

## 🐛 Tratamento de Erros

O programa trata os seguintes casos de erro:
- Argumentos não numéricos
- Números duplicados
- Overflow de inteiros
- Entrada vazia

Em caso de erro, o programa exibe "Error\n" e termina com status de erro.

## 🧪 Testes

Para testar o programa:

```bash
# Teste básico
./push_swap 3 1 2

# Teste com números já ordenados
./push_swap 1 2 3 4 5

# Teste com números em ordem reversa
./push_swap 5 4 3 2 1

# Teste de erro - números duplicados
./push_swap 1 2 2 3

# Teste de erro - entrada inválida
./push_swap 1 abc 3
```

## 👤 Autor

**Tiberio Bezerra** - [@tbezerrasoares](https://github.com/tbezerrasoares)
- 42 Login: `tbezerra`
- Email: tbezerra@student.42porto.com

---

### 📝 Nota
Este projeto foi desenvolvido como parte do currículo da 42 School Porto. O código segue a Norma da 42 e todas as práticas recomendadas da escola.

**Ano:** 2024  
**Campus:** 42 Porto
