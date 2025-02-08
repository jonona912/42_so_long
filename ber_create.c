/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:13:49 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/02/03 19:17:06 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// void createBerFile(const char* filename) {
//     FILE *file = fopen(filename, "w");
//     if (file == NULL) {
//         perror("Error creating .ber file");
//         return;
//     }

//     // Example map data
//     const char *map[] = {
//         "111111\n",
//         "1P00E1\n",
//         "1C0C01\n",
//         "111111\n"
//     };

//     // Write the map to the file
//     for (int i = 0; i < 4; i++) {
//         fprintf(file, "%s", map[i]);
//     }

//     fclose(file);
//     printf("Created .ber file: %s\n", filename);
// }

int	main(void)
{
	const char	*filename;

	filename = "valid_map.ber";
	createBerFile(filename);
	return (0);
}
