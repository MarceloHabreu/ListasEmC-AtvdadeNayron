# Sistema de Gerenciamento de Tarefas em C

Este projeto foi desenvolvido como parte de uma atividade prática sobre **Listas em C**, um dos conceitos fundamentais em estruturas de dados. Ele implementa um sistema de gerenciamento de tarefas, utilizando listas encadeadas para realizar operações de CRUD (Create, Read, Update, Delete) de maneira eficiente e dinâmica.

## 🔧 Tecnologias Utilizadas

- Linguagem de programação **C**

## ✨ Funcionalidades

O sistema permite:

1. **Adicionar novas tarefas**: Insere uma nova tarefa na lista com título, descrição e status de pendência.
2. **Remover tarefas**: Exclui uma tarefa específica com base no título.
3. **Buscar tarefas**: Localiza uma tarefa pelo título e exibe seus detalhes.
4. **Exibir todas as tarefas pendentes**: Lista apenas as tarefas que ainda estão marcadas como pendentes.
5. **Atualizar status de pendência**: Permite alterar o status de uma tarefa específica entre concluída e pendente.

## 🗋 Estruturas e Conceitos Utilizados

### Estrutura `Task`

Cada tarefa é representada pela seguinte estrutura:

```c
typedef struct task {
  char title[50];
  char description[100];
  int pending; // 1 -> Concluída, 2 -> Pendente
  struct task* next;
} Task;
```

### Lista Encadeada

A lista encadeada utiliza um ponteiro para o primeiro nó da lista (`head`). As operações são realizadas iterando sobre os nós ou manipulando os ponteiros diretamente.

### Funções Implementadas

- **Criar Tarefa**

  Cria uma nova tarefa e retorna um ponteiro para a mesma.

  ```c
  Task* createTask(char* title, char* description, int pending);
  ```

- **Adicionar Tarefa**

  Insere uma nova tarefa no final da lista.

  ```c
  void addTask(Task** head, char* title, char* description, int pending);
  ```

- **Remover Tarefa**

  Exclui uma tarefa com base no título.

  ```c
  void removeTask(Task** head, char* title);
  ```

- **Buscar Tarefa**

  Localiza e retorna uma tarefa pelo título.

  ```c
  Task* searchTask(Task* head, char* title);
  ```

- **Exibir Tarefas Pendentes**

  Itera sobre a lista e exibe todas as tarefas com status pendente.

  ```c
  void displayTasks(Task* head);
  ```

- **Atualizar Status de Pendência**

  Altera o status de pendência de uma tarefa específica.

  ```c
  void updatePending(Task* head, char* title, int pending);
  ```

### Fluxo Principal

O programa apresenta um menu interativo que permite ao usuário realizar as operações mencionadas:

```c
do {
  printf("\nMenu de Tarefas:\n");
  printf("1. Adicionar nova tarefa\n");
  printf("2. Remover tarefa\n");
  printf("3. Buscar tarefa\n");
  printf("4. Exibir todas as tarefas pendentes\n");
  printf("5. Atualizar pendência das tarefas\n");
  printf("0. Sair\n");
  printf("Escolha uma opcao: ");
  scanf("%d", &choice);
  getchar(); // Limpar o buffer do teclado

  switch (choice) {
    case 1:
      // Adicionar nova tarefa
      break;
    case 2:
      // Remover tarefa
      break;
    case 3:
      // Buscar tarefa
      break;
    case 4:
      // Exibir tarefas pendentes
      break;
    case 5:
      // Atualizar pendência
      break;
    case 0:
      printf("Saindo do menu...\n");
      break;
    default:
      printf("Opção inválida!\n");
  }
} while (choice != 0);
```

## 🔑 Compilação e Execução

Para compilar e executar o programa:

1. Salve o código em um arquivo, por exemplo, `tarefas.c`.
2. Compile usando o GCC:
   ```bash
   gcc tarefas.c -o tarefas
   ```
3. Execute o programa:
   ```bash
   ./tarefas
   ```

## 🙏 Considerações Finais

Este projeto foi essencial para explorar o uso de **listas encadeadas** e aprimorar o entendimento sobre alocação dinâmica de memória e manipulação de ponteiros. Ele demonstra como essas estruturas são fundamentais para resolver problemas complexos de forma eficiente e organizada. Além disso, destaca a importância de boas práticas na construção de sistemas modulares e extensíveis.

