 obj-m+=core/chunk.o core/cpu.o core/cpuid.c core/dump_vmcs.c core/emulate.c \
	 core/ept.c core/ept2.c core/ept_tree.c core/gpa_space.c core/hax.c core/ia32.c core/intr_exc.c core/memory.c core/memslot.c core/page_walker.c core/ramblock.c core/vcpu.c core/vm.c core/vmcs_names.c core/vmx.c core/vtlb.c
 #TODO
 # core/emulate_ops.asm
 # core/ia32_ops.asm
 # core/vmx_ops.asm

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) \
	EXTRA_CFLAGS="-Wno-error=strict-prototypes \
	-I${PWD}/include \
	-I/usr/include" \
	 modules
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
