/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:41:08 by yzakharc          #+#    #+#             */
/*   Updated: 2017/09/02 18:41:09 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int 	or_instr(t_skrr *skrr, t_proc *process)
{
	unsigned char	*q;
	int 			address;
	int 			reg;

	if ((process->waiting_cycles) == (g_tab[skrr->op].cycles))
	{
		if (!(q = malloc(sizeof(unsigned char) * g_tab[skrr->op].numb_of_arg)))
			exit(0);
		if (!(same_start(q, skrr, process, g_tab[skrr->op].numb_of_arg)))
			return (0);
		address = determination_of_action(q, skrr, 0, 4, process);
		process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
		if (!(reg = reg_param(skrr, process, 2)) && (g_err) && !(g_err = 0))
			return (0);
		process->registry[reg] = (unsigned int) address;
		process->carry = (address == 0) ? 1 : 0;
		process->pc = ((process->pc + skrr->chmp->offset + 2 + MEM_SIZE) % MEM_SIZE);
		process->tmp_pc = process->pc;
		process->waiting_cycles = 0;
	}
	return (1);
}
