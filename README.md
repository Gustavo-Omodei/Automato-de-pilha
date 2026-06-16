# Autômato com Pilha (Pushdown Automaton - PDA) em C++

Este projeto é uma implementação em C++ de um **Autômato com Pilha Determinístico**, desenvolvido para reconhecer a linguagem livre de contexto clássica:

$$L = \{a^n b^n \mid n \geq 1\}$$

Isso significa que o programa aceita strings que possuem uma sequência de letras `a` seguidas por uma quantidade **exatamente igual** de letras `b` (ex: `ab`, `aabb`, `aaabbb`). Caso as quantidades sejam diferentes ou a ordem esteja errada (ex: `ba`, `aab`), a string é rejeitada.

---

## 🛠️ Como Funciona o Autômato

O autômato utiliza o princípio de empilhar elementos para "contar" a quantidade de caracteres lidos. Ele funciona baseado em uma máquina de 3 estados:

1. **Estado $q_0$ (Inicial):** Lê os caracteres `'a'`. Para cada `'a'` lido, ele empilha um caractere de controle `'A'`. Se encontrar o primeiro `'b'`, ele desempilha um `'A'` e muda para o estado $q_1$.
2. **Estado $q_1$:** Lê os caracteres `'b'`. Para cada `'b'` lido, desempilha um `'A'`.
3. **Estado REJEITADO:** Se houver qualquer fuga das regras (ex: tentar ler `'b'` com a pilha vazia, ou ler `'a'` depois de já ter lido um `'b'`), o autômato vai para este estado de erro.

### Condição de Aceitação:
A string só será **ACEITA** se, ao terminar de ler todos os caracteres, o autômato estiver no estado $q_1$ e a pilha estiver completamente **vazia**.

---

## 🚀 Como Executar no Dev-C++

Como o código utiliza funcionalidades do C++ moderno (C++11), siga estes passos para garantir que ele compile perfeitamente:

1. Abra o **Dev-C++**.
2. Vá no menu superior: **Ferramentas (Tools)** > **Opções do Compilador (Compiler Options)**.
3. Na aba **Geral (General)**, marque a caixinha: *Adicionar estes comandos quando chamar o compilador*.
4. No campo de texto logo abaixo, digite:
```text
   -std=c++11
