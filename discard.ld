/* Auxiliary linker script: discard sections that modern binutils emits but
 * the PSP PRX loader can't handle. .MIPS.abiflags in particular gets a stray
 * LMA that collides with .text when loaded. Pass via -Wl,-T,discard.ld
 * alongside the SDK's linkfile.prx; entries here are merged.
 */
SECTIONS
{
  /DISCARD/ : { *(.MIPS.abiflags) *(.eh_frame*) *(.gnu.attributes) }
}
