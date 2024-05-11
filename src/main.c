/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:44:19 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/11 19:47:50 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	minirt_loop(int argc, char **argv)
{
	(void) argv;
	(void) argc;
	mlx_test();
	//while (1)
	//	continue ;
	return (0);
}

// create scree, statica de con mlx, primera ventana la inicializa

int main (int argc, char **argv)
{
	printf("oOoOoOoOoOooOoOoOoOoOo|   miniRT   |oOoOoOoOoOooOoOoOoOoOo\n");
#ifdef DEBUG
	// debug code
#endif
	minirt_loop(argc, argv);
	return (EXIT_SUCCESS);
}
