/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:45:45 by sopperma          #+#    #+#             */
/*   Updated: 2024/10/04 13:55:40 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void cleanup(t_memory *memory)
{
    
    t_philosopher *first_philosopher;
    t_philosopher *tmp;

    first_philosopher = memory->philosophers;
    while (philosopher)
    {
        tmp = philosopher;
        pthread_destroy_mutex(philosopher->fork_mutex);
        pthread_destroy_mutex(philosopher->last_meal_mutex);
        // pthread_destroy_mutex(philosopher->is);
        
        
        philosopher = philosopher->next;
  
    }
    free(memory->print_mutex);
    free(memory->died_mutex);
    free(memory->full_mutex);
    free(memory->all_full_mutex);
    free(memory);
}