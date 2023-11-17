#include "shell.h"

/**
 * clear_info - it sets up info_t structure.
 * @info: addy of structure.
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}
