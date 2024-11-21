#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int main() //lst_new
{
    char *content = "Hello, world!";
    
    t_list *new_elem = ft_lstnew((void *)content);

    if (new_elem == NULL)
    {
        printf("Échec : ft_lstnew a retourné NULL.\n");
        return (1);
    }

    if (new_elem->content != content)
    {
        printf("Échec : Le contenu n'a pas été correctement assigné.\n");
        free(new_elem);
        return (1);
    }

    if (new_elem->next != NULL)
    {
        printf("Échec : Le champ next n'est pas NULL.\n");
        free(new_elem);
        return (1);
    }

    printf("Succès : ft_lstnew a passé tous les tests.\n");

    free(new_elem);
    return (0);
}

/*int main() // ft_lstsize
{
    t_list *elem1 = ft_lstnew("Element 1");
    t_list *elem2 = ft_lstnew("Element 2");
    t_list *elem3 = ft_lstnew("Element 3");

    if (!elem1 || !elem2 || !elem3)
    {
        printf("Échec : Échec de la création des éléments de test.\n");
        free(elem1);
        free(elem2);
        free(elem3);
        return (1);
    }

    elem1->next = elem2;
    elem2->next = elem3;
    elem3->next = NULL;

    int size = ft_lstsize(elem1);

    if (size != 3)
    {
        printf("Échec : La taille calculée est incorrecte. Attendu: 3, Reçu: %d\n", size);
        free(elem3);
        free(elem2);
        free(elem1);
        return (1);
    }

    if (ft_lstsize(NULL) != 0)
    {
        printf("Échec : La taille d'une liste vide n'est pas 0.\n");
        free(elem3);
        free(elem2);
        free(elem1);
        return (1);
    }

    printf("Succès : ft_lstsize a passé tous les tests.\n");

    free(elem3);
    free(elem2);
    free(elem1);
    return (0);
}*/

/*int main() // ft_lstadd_front
{
    t_list *head = ft_lstnew("Second Element");
    t_list *new_elem = ft_lstnew("First Element");

    if (!head || !new_elem)
    {
        printf("Échec : Échec de la création des éléments de test.\n");
        free(head);
        free(new_elem);
        return (1);
    }

    ft_lstadd_front(&head, new_elem);

    if (head != new_elem)
    {
        printf("Échec : L'élément ajouté n'est pas la nouvelle tête de liste.\n");
        free(head->next);
        free(head);
        return (1);
    }

    if (new_elem->next != head->next)
    {
        printf("Échec : Le champ next du nouvel élément n'est pas correctement assigné.\n");
        free(head->next);
        free(head);
        return (1);
    }

    if (head->content != new_elem->content || head->next->content != "Second Element")
    {
        printf("Échec : Les contenus ne correspondent pas après l'ajout.\n");
        free(head->next); // Libérer l'ancien élément
        free(head);
        return (1);
    }

    printf("Succès : ft_lstadd_front a passé tous les tests.\n");

    free(head->next);
    free(head);
    return (0);
}*/

/*void del_content(void *content)
{
    free(content);
}
int main() // ft_lstclear
{
    char *content1 = malloc(20);
    char *content2 = malloc(20);
    char *content3 = malloc(20);

    if (!content1 || !content2 || !content3)
    {
        printf("Échec : Allocation mémoire pour le contenu.\n");
        free(content1);
        free(content2);
        free(content3);
        return (1);
    }

    snprintf(content1, 20, "Element 1");
    snprintf(content2, 20, "Element 2");
    snprintf(content3, 20, "Element 3");

    t_list *elem1 = ft_lstnew(content1);
    t_list *elem2 = ft_lstnew(content2);
    t_list *elem3 = ft_lstnew(content3);

    if (!elem1 || !elem2 || !elem3)
    {
        printf("Échec : Échec de la création des éléments de test.\n");
        free(content1);
        free(content2);
        free(content3);
        free(elem1);
        free(elem2);
        free(elem3);
        return (1);
    }

    elem1->next = elem2;
    elem2->next = elem3;

    if (ft_lstsize(elem1) != 3)
    {
        printf("Échec : La liste devrait contenir 3 éléments avant ft_lstclear.\n");
        free(elem3);
        free(elem2);
        free(elem1);
        return (1);
    }

    ft_lstclear(&elem1, del_content);

    if (elem1 != NULL)
    {
        printf("Échec : La liste n'est pas vide après ft_lstclear.\n");
        return (1);
    }

    printf("Succès : ft_lstclear a passé tous les tests.\n");

    return (0);
}*/

//lstmap
/*void del_content(void *content)
{
    free(content);
}

void *duplicate_content(void *content)
{
    char *str = (char *)content;
    char *new_str = malloc(strlen(str) + 1);
    if (!new_str)
        return (NULL);
    strcpy(new_str, str);
    return (new_str);
}

int main()
{
    t_list *elem1 = ft_lstnew(strdup("Element 1"));
    t_list *elem2 = ft_lstnew(strdup("Element 2"));
    t_list *elem3 = ft_lstnew(strdup("Element 3"));

    if (!elem1 || !elem2 || !elem3)
    {
        printf("Échec : Échec de la création des éléments de test.\n");
        free(elem1);
        free(elem2);
        free(elem3);
        return (1);
    }

    elem1->next = elem2;
    elem2->next = elem3;

    t_list *new_list = ft_lstmap(elem1, duplicate_content, del_content);

    if (!new_list)
    {
        printf("Échec : La nouvelle liste est NULL.\n");
        ft_lstclear(&elem1, del_content);
        return (1);
    }

    if (ft_lstsize(new_list) != ft_lstsize(elem1))
    {
        printf("Échec : La taille des listes est différente.\n");
        ft_lstclear(&elem1, del_content);
        ft_lstclear(&new_list, del_content);
        return (1);
    }

    t_list *original = elem1;
    t_list *mapped = new_list;
    while (original && mapped)
    {
        if (strcmp((char *)original->content, (char *)mapped->content) != 0)
        {
            printf("Échec : Le contenu des éléments ne correspond pas après transformation.\n");
            ft_lstclear(&elem1, del_content);
            ft_lstclear(&new_list, del_content);
            return (1);
        }
        if (original->content == mapped->content)
        {
            printf("Échec : Les contenus sont identiques (pas de duplication).\n");
            ft_lstclear(&elem1, del_content);
            ft_lstclear(&new_list, del_content);
            return (1);
        }
        original = original->next;
        mapped = mapped->next;
    }

    if (ft_lstsize(elem1) != 3)
    {
        printf("Échec : La liste originale a été modifiée.\n");
        ft_lstclear(&elem1, del_content);
        ft_lstclear(&new_list, del_content);
        return (1);
    }

    printf("Succès : ft_lstmap a passé tous les tests.\n");

    ft_lstclear(&elem1, del_content);
    ft_lstclear(&new_list, del_content);
    return (0);
}*/
