
#pragma once

/**
 * Install and apply suitable BIOS patches.
 */
void patcher_apply(void);

extern bool enable_unlock; // Don't do anti-FreePSXBoot patches on Japanese consoles since they don't work
