#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de um nó que representa uma tarefa
typedef struct task {
  char title[50];
  char description[100];
  int pending; // 1 feita Or 2 pendente
  struct task* next;
} Task;

// Função para criar uma nova tarefa
Task* createTask(char* title, char* description, int pending) {
  Task* newTask = (Task*)malloc(sizeof(Task));
  strcpy(newTask->title, title);
  strcpy(newTask->description, description);
  newTask->pending = pending;
  newTask->next = NULL;
  printf("Task created successfully\n");
  return newTask;
}

// Função para adicionar uma nova tarefa ao final da lista
void addTask(Task** head, char* title, char* description, int pending) {
  Task* newTask = createTask(title, description, pending);
  if (*head == NULL) {
    *head = newTask;
  } else {
    Task* atualTask = *head;
    while (atualTask->next != NULL) {
      atualTask = atualTask->next;
    }
    atualTask->next = newTask;
  }
}

// Função para remover uma tarefa específica
void removeTask(Task** head, char* title) {
  if (*head == NULL) {
    printf("List empty!! \n");
    return;
  }

  Task* atual = *head;
  Task* anterior = NULL;

  if (strcmp(atual->title, title) == 0) {
    *head = atual->next;
    free(atual);
    printf("Task with title %s successfully removed!! \n", title);
    return;
  }

  while (atual != NULL && strcmp(atual->title, title) != 0) {
    anterior = atual;
    atual = atual->next;
  }

  if (atual == NULL) {
    printf("Task with title %s not found!!\n", title);
    return; 
  }

  anterior->next = atual->next;
  free(atual);
  printf("Task with title %s successfully removed!! \n", title);
}

// Função para buscar uma tarefa na lista
Task* searchTask(Task* head, char* title) {
  if (head == NULL) {
    printf("List empty!! \n");
    return NULL;
  }

  Task* atual = head;
  while (atual != NULL) {
    if (strcmp(atual->title, title) == 0) {
      printf("Title: %s, Description: %s.\n", atual->title, atual->description);
      return atual;
    }
    atual = atual->next;
  }
  printf("Task title not found!!\n");
  return NULL;
}

// Função para exibir todas as tarefas pendentes
void displayTasks(Task* head) {
  if (head == NULL) {
    printf("No pending tasks!!\n");
    return;
  }

  Task* atual = head;
  printf("Pending tasks: \n");
  while (atual != NULL) {
    if (atual->pending == 2) {
      printf("Title: %s, Description: %s.\n", atual->title, atual->description);
    }
    atual = atual->next;
  }
}

// Adicionando uma função ao sistema (função para atualizar pendencia)
void updatePending(Task* head, char* title, int pending) {
  Task* taskToUpdate = searchTask(head, title);
  if (taskToUpdate != NULL) {
    taskToUpdate->pending = pending;
    printf("Task '%s' updated successfully to pending status %d.\n", title, pending);
  } else {
    printf("Task not found.\n");
  }
  
}

int main() {
  Task* head = NULL;
  int choice;
  char title[50];
  char description[100];
  int pending;

  do {
    printf("\nMenu de Tarefas:\n");
    printf("1. Adicionar nova tarefa\n");
    printf("2. Remover tarefa\n");
    printf("3. Buscar tarefa\n");
    printf("4. Exibir todas as tarefas pendentes\n");
    printf("5. Atualizar pendecia das tarefas\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &choice);
    getchar(); // Limpar o buffer do teclado

    switch (choice) {
    case 1:
      printf("Digite o titulo da tarefa: ");
      fgets(title, sizeof(title), stdin);
      title[strcspn(title, "\n")] = '\0';
      printf("Digite a descricao da tarefa: ");
      fgets(description, sizeof(description), stdin);
      description[strcspn(description, "\n")] = '\0';
      printf("Digite a pendencia da tarefa([1]->Concluida, [2]-> A fazer): ");
      scanf("%d", &pending);
      if (pending == 1 || pending == 2) {
         getchar();
         addTask(&head, title, description, pending);
      } else {
        printf("Try again by entering correct values: ([1]->Concluida, [2]-> A fazer)\n");
      }
      break;
    case 2:
      printf("Digite o Titulo da tarefa que deseja excluir: ");
      fgets(title, sizeof(title), stdin);
      title[strcspn(title, "\n")] = '\0';
      removeTask(&head, title);
      break;
    case 3:
      printf("Digite o Titulo da tarefa que deseja buscar: ");
      fgets(title, sizeof(title), stdin);
      title[strcspn(title, "\n")] = '\0';
      searchTask(head, title);
      break;
    case 4:
      displayTasks(head);
      break;
    case 5:
      printf("Digite o Titulo da tarefa que deseja atualizar pendencia: ");
      fgets(title, sizeof(title), stdin);
      title[strcspn(title, "\n")] = '\0';
      printf("Digite o novo status de pendencia da tarefa([1]->Concluida, [2]-> A fazer): ");
      scanf("%d", &pending);
      if (pending == 1 || pending == 2) {
         getchar();
         updatePending(head, title, pending);
      } else {
        printf("Try again by entering correct values: ([1]->Concluida, [2]-> A fazer)\n");
      }
      break;
    case 0:
      printf("Saindo do menu...\n");
      break;
    default:
      printf("Opção inválida!\n");
    }
  } while (choice != 0);

  return 0;
}
