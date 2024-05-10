/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:32:13 by mac               #+#    #+#             */
/*   Updated: 2024/05/10 10:43:31 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ryusupov_h/ryusupov.h"

char **new_split(const char *input, int *argc) {
    int count = 0;
    int i = 0;
    while (input[i] != '\0') {
        while (input[i] == ' ') {
            i++;
        }
        if (input[i] != '\0') {
            count++;
        }
        while (input[i] != ' ' && input[i] != '\0') {
            i++;
        }
    }

    char **tokens = malloc((count + 1) * sizeof(char *));
    if (tokens == NULL) {
        return NULL;
    }

    i = 0;
    int token_index = 0;
    while (input[i] != '\0') {
        while (input[i] == ' ') {
            i++;
        }
        int start = i;
        while (input[i] != ' ' && input[i] != '\0') {
            i++;
        }
        tokens[token_index] = malloc((i - start + 1) * sizeof(char));
        if (tokens[token_index] == NULL) {

            for (int j = 0; j < token_index; j++) {
                free(tokens[j]);
            }
            free(tokens);
            return NULL;
        }

        strncpy(tokens[token_index], input + start, i - start);
        tokens[token_index][i - start] = '\0';
        token_index++;
    }

    tokens[count] = NULL;
    *argc = count;
    return tokens;
}
