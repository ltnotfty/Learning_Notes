cmake_minimum_required(VERSION 3.18)
project(basicfwd)

set(CMAKE_CXX_STANDARD 14)
set(TARGET "basicfwd")



cmake_host_system_information(RESULT os_platform QUERY  OS_PLATFORM)
message(STATUS " >> ${os_platform} << ")


## arm 64
if(${os_platform} STREQUAL "aarch64")


    message(STATUS "AMD64")

    add_compile_options(
            #        -m64
            -march=armv8.2-a+crc+crypto+lse
            #-m64
    )

    link_directories(/data/dpdk-19.11/arm64-octeontx2-linuxapp-gcc/lib/)
    include_directories(/data/dpdk-19.11/arm64-octeontx2-linuxapp-gcc/include/)
    include_directories(src)


    file(GLOB_RECURSE  all_source  src/*.cpp )
    add_executable(basicfwd ${all_source} main.cpp)



    set(DPDKLIBS
            -Wl,--whole-archive
            librte_flow_classify.a
            librte_pipeline.a
            librte_table.a
            librte_port.a
            # -Wl,--no-whole-archive
            librte_pdump.a
            librte_distributor.a
            librte_ip_frag.a
            librte_meter.a
            librte_fib.a
            librte_rib.a
            librte_lpm.a
            librte_acl.a
            librte_jobstats.a
            librte_metrics.a
            librte_bitratestats.a
            librte_latencystats.a
            librte_power.a
            librte_efd.a
            librte_bpf.a
            librte_ipsec.a
            -Wl,--whole-archive
            librte_cfgfile.a
            librte_gro.a
            librte_gso.a
            librte_hash.a
            librte_member.a
            librte_vhost.a
            librte_kvargs.a
            librte_mbuf.a
            librte_net.a
            librte_ethdev.a
            librte_bbdev.a
            librte_cryptodev.a
            librte_security.a
            librte_compressdev.a
            librte_eventdev.a
            librte_rawdev.a
            librte_timer.a
            librte_mempool.a
            librte_stack.a
            librte_mempool_ring.a
            librte_mempool_octeontx2.a
            librte_ring.a
            librte_pci.a
            librte_eal.a
            librte_cmdline.a
            librte_reorder.a
            librte_sched.a
            librte_rcu.a
            librte_common_cpt.a
            librte_common_octeontx.a
            librte_common_octeontx2.a
            librte_common_dpaax.a
            librte_bus_pci.a
            librte_bus_vdev.a
            librte_bus_fslmc.a
            librte_mempool_bucket.a
            librte_mempool_stack.a
            librte_pmd_af_packet.a
            librte_pmd_e1000.a
            librte_pmd_ena.a
            librte_pmd_failsafe.a
            librte_pmd_i40e.a
            librte_pmd_iavf.a
            librte_pmd_ice.a
            librte_pmd_ixgbe.a
            librte_pmd_octeontx_ep.a
            librte_pmd_memif.a
            librte_pmd_nfp.a
            librte_pmd_null.a
            librte_pmd_octeontx2.a
            librte_pmd_ring.a
            librte_pmd_tap.a
            librte_pmd_vdev_netvsc.a
            librte_pmd_virtio.a
            librte_pmd_vhost.a
            librte_pmd_ifc.a
            librte_pmd_vmxnet3_uio.a
            librte_bus_vmbus.a
            librte_pmd_netvsc.a
            librte_pmd_bbdev_null.a
            librte_pmd_bbdev_fpga_lte_fec.a
            librte_pmd_bbdev_turbo_sw.a
            librte_pmd_null_crypto.a
            librte_pmd_nitrox.a
            librte_pmd_octeontx_crypto.a
            librte_pmd_octeontx2_crypto.a
            librte_pmd_crypto_scheduler.a
            librte_pmd_virtio_crypto.a
            librte_pmd_octeontx_zip.a
            librte_pmd_qat.a
            librte_pmd_skeleton_event.a
            librte_pmd_sw_event.a
            librte_pmd_dsw_event.a
            librte_pmd_octeontx_ssovf.a
            librte_mempool_octeontx.a
            librte_pmd_octeontx.a
            librte_pmd_octeontx2_event.a
            librte_pmd_opdl_event.a
            librte_rawdev_skeleton.a
            librte_bus_ifpga.a
            librte_rawdev_ntb.a
            librte_rawdev_octeontx2_dma.a
            librte_rawdev_octeontx2_ep.a
            -Wl,--no-whole-archive
            #-Wl,-lrt
            #-Wl,-lm
            #-Wl,-ldl
            )


    target_link_libraries(basicfwd  ${DPDKLIBS} dl pthread)

endif()

## arm

