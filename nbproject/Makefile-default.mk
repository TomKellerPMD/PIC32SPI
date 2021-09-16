#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PIC32SPI.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PIC32SPI.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../PIC32Redux/PIC32Redux.X/C-Motion/C/c-motion.c ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDcommon.c ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDdiag.c ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDpic32SPI.c ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDsys.c ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDtrans.c ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDutil.c ../PIC32Redux/PIC32Redux.X/DBPrint.c PIC32Libs/ConfigBit.c PMDApp.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1074706855/c-motion.o ${OBJECTDIR}/_ext/1074706855/PMDcommon.o ${OBJECTDIR}/_ext/1074706855/PMDdiag.o ${OBJECTDIR}/_ext/1074706855/PMDpic32SPI.o ${OBJECTDIR}/_ext/1074706855/PMDsys.o ${OBJECTDIR}/_ext/1074706855/PMDtrans.o ${OBJECTDIR}/_ext/1074706855/PMDutil.o ${OBJECTDIR}/_ext/1738135402/DBPrint.o ${OBJECTDIR}/PIC32Libs/ConfigBit.o ${OBJECTDIR}/PMDApp.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1074706855/c-motion.o.d ${OBJECTDIR}/_ext/1074706855/PMDcommon.o.d ${OBJECTDIR}/_ext/1074706855/PMDdiag.o.d ${OBJECTDIR}/_ext/1074706855/PMDpic32SPI.o.d ${OBJECTDIR}/_ext/1074706855/PMDsys.o.d ${OBJECTDIR}/_ext/1074706855/PMDtrans.o.d ${OBJECTDIR}/_ext/1074706855/PMDutil.o.d ${OBJECTDIR}/_ext/1738135402/DBPrint.o.d ${OBJECTDIR}/PIC32Libs/ConfigBit.o.d ${OBJECTDIR}/PMDApp.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1074706855/c-motion.o ${OBJECTDIR}/_ext/1074706855/PMDcommon.o ${OBJECTDIR}/_ext/1074706855/PMDdiag.o ${OBJECTDIR}/_ext/1074706855/PMDpic32SPI.o ${OBJECTDIR}/_ext/1074706855/PMDsys.o ${OBJECTDIR}/_ext/1074706855/PMDtrans.o ${OBJECTDIR}/_ext/1074706855/PMDutil.o ${OBJECTDIR}/_ext/1738135402/DBPrint.o ${OBJECTDIR}/PIC32Libs/ConfigBit.o ${OBJECTDIR}/PMDApp.o

# Source Files
SOURCEFILES=../PIC32Redux/PIC32Redux.X/C-Motion/C/c-motion.c ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDcommon.c ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDdiag.c ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDpic32SPI.c ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDsys.c ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDtrans.c ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDutil.c ../PIC32Redux/PIC32Redux.X/DBPrint.c PIC32Libs/ConfigBit.c PMDApp.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/PIC32SPI.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MZ2048EFM100
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1074706855/c-motion.o: ../PIC32Redux/PIC32Redux.X/C-Motion/C/c-motion.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1074706855" 
	@${RM} ${OBJECTDIR}/_ext/1074706855/c-motion.o.d 
	@${RM} ${OBJECTDIR}/_ext/1074706855/c-motion.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1074706855/c-motion.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"PIC32Libs/bsp" -I"PIC32Libs/framework" -I"PIC32Libs/periph" -I"PIC32Libs" -I"C-Motion/Include" -I"." -MMD -MF "${OBJECTDIR}/_ext/1074706855/c-motion.o.d" -o ${OBJECTDIR}/_ext/1074706855/c-motion.o ../PIC32Redux/PIC32Redux.X/C-Motion/C/c-motion.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1074706855/PMDcommon.o: ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDcommon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1074706855" 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDcommon.o.d 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDcommon.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1074706855/PMDcommon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"PIC32Libs/bsp" -I"PIC32Libs/framework" -I"PIC32Libs/periph" -I"PIC32Libs" -I"C-Motion/Include" -I"." -MMD -MF "${OBJECTDIR}/_ext/1074706855/PMDcommon.o.d" -o ${OBJECTDIR}/_ext/1074706855/PMDcommon.o ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDcommon.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1074706855/PMDdiag.o: ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDdiag.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1074706855" 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDdiag.o.d 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDdiag.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1074706855/PMDdiag.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"PIC32Libs/bsp" -I"PIC32Libs/framework" -I"PIC32Libs/periph" -I"PIC32Libs" -I"C-Motion/Include" -I"." -MMD -MF "${OBJECTDIR}/_ext/1074706855/PMDdiag.o.d" -o ${OBJECTDIR}/_ext/1074706855/PMDdiag.o ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDdiag.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1074706855/PMDpic32SPI.o: ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDpic32SPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1074706855" 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDpic32SPI.o.d 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDpic32SPI.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1074706855/PMDpic32SPI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"PIC32Libs/bsp" -I"PIC32Libs/framework" -I"PIC32Libs/periph" -I"PIC32Libs" -I"C-Motion/Include" -I"." -MMD -MF "${OBJECTDIR}/_ext/1074706855/PMDpic32SPI.o.d" -o ${OBJECTDIR}/_ext/1074706855/PMDpic32SPI.o ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDpic32SPI.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1074706855/PMDsys.o: ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDsys.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1074706855" 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDsys.o.d 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDsys.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1074706855/PMDsys.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"PIC32Libs/bsp" -I"PIC32Libs/framework" -I"PIC32Libs/periph" -I"PIC32Libs" -I"C-Motion/Include" -I"." -MMD -MF "${OBJECTDIR}/_ext/1074706855/PMDsys.o.d" -o ${OBJECTDIR}/_ext/1074706855/PMDsys.o ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDsys.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1074706855/PMDtrans.o: ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDtrans.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1074706855" 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDtrans.o.d 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDtrans.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1074706855/PMDtrans.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"PIC32Libs/bsp" -I"PIC32Libs/framework" -I"PIC32Libs/periph" -I"PIC32Libs" -I"C-Motion/Include" -I"." -MMD -MF "${OBJECTDIR}/_ext/1074706855/PMDtrans.o.d" -o ${OBJECTDIR}/_ext/1074706855/PMDtrans.o ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDtrans.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1074706855/PMDutil.o: ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDutil.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1074706855" 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDutil.o.d 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDutil.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1074706855/PMDutil.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"PIC32Libs/bsp" -I"PIC32Libs/framework" -I"PIC32Libs/periph" -I"PIC32Libs" -I"C-Motion/Include" -I"." -MMD -MF "${OBJECTDIR}/_ext/1074706855/PMDutil.o.d" -o ${OBJECTDIR}/_ext/1074706855/PMDutil.o ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDutil.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1738135402/DBPrint.o: ../PIC32Redux/PIC32Redux.X/DBPrint.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1738135402" 
	@${RM} ${OBJECTDIR}/_ext/1738135402/DBPrint.o.d 
	@${RM} ${OBJECTDIR}/_ext/1738135402/DBPrint.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1738135402/DBPrint.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"PIC32Libs/bsp" -I"PIC32Libs/framework" -I"PIC32Libs/periph" -I"PIC32Libs" -I"C-Motion/Include" -I"." -MMD -MF "${OBJECTDIR}/_ext/1738135402/DBPrint.o.d" -o ${OBJECTDIR}/_ext/1738135402/DBPrint.o ../PIC32Redux/PIC32Redux.X/DBPrint.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/PIC32Libs/ConfigBit.o: PIC32Libs/ConfigBit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/PIC32Libs" 
	@${RM} ${OBJECTDIR}/PIC32Libs/ConfigBit.o.d 
	@${RM} ${OBJECTDIR}/PIC32Libs/ConfigBit.o 
	@${FIXDEPS} "${OBJECTDIR}/PIC32Libs/ConfigBit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"PIC32Libs/bsp" -I"PIC32Libs/framework" -I"PIC32Libs/periph" -I"PIC32Libs" -I"C-Motion/Include" -I"." -MMD -MF "${OBJECTDIR}/PIC32Libs/ConfigBit.o.d" -o ${OBJECTDIR}/PIC32Libs/ConfigBit.o PIC32Libs/ConfigBit.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/PMDApp.o: PMDApp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PMDApp.o.d 
	@${RM} ${OBJECTDIR}/PMDApp.o 
	@${FIXDEPS} "${OBJECTDIR}/PMDApp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"PIC32Libs/bsp" -I"PIC32Libs/framework" -I"PIC32Libs/periph" -I"PIC32Libs" -I"C-Motion/Include" -I"." -MMD -MF "${OBJECTDIR}/PMDApp.o.d" -o ${OBJECTDIR}/PMDApp.o PMDApp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/_ext/1074706855/c-motion.o: ../PIC32Redux/PIC32Redux.X/C-Motion/C/c-motion.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1074706855" 
	@${RM} ${OBJECTDIR}/_ext/1074706855/c-motion.o.d 
	@${RM} ${OBJECTDIR}/_ext/1074706855/c-motion.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1074706855/c-motion.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"PIC32Libs/bsp" -I"PIC32Libs/framework" -I"PIC32Libs/periph" -I"PIC32Libs" -I"C-Motion/Include" -I"." -MMD -MF "${OBJECTDIR}/_ext/1074706855/c-motion.o.d" -o ${OBJECTDIR}/_ext/1074706855/c-motion.o ../PIC32Redux/PIC32Redux.X/C-Motion/C/c-motion.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1074706855/PMDcommon.o: ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDcommon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1074706855" 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDcommon.o.d 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDcommon.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1074706855/PMDcommon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"PIC32Libs/bsp" -I"PIC32Libs/framework" -I"PIC32Libs/periph" -I"PIC32Libs" -I"C-Motion/Include" -I"." -MMD -MF "${OBJECTDIR}/_ext/1074706855/PMDcommon.o.d" -o ${OBJECTDIR}/_ext/1074706855/PMDcommon.o ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDcommon.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1074706855/PMDdiag.o: ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDdiag.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1074706855" 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDdiag.o.d 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDdiag.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1074706855/PMDdiag.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"PIC32Libs/bsp" -I"PIC32Libs/framework" -I"PIC32Libs/periph" -I"PIC32Libs" -I"C-Motion/Include" -I"." -MMD -MF "${OBJECTDIR}/_ext/1074706855/PMDdiag.o.d" -o ${OBJECTDIR}/_ext/1074706855/PMDdiag.o ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDdiag.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1074706855/PMDpic32SPI.o: ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDpic32SPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1074706855" 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDpic32SPI.o.d 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDpic32SPI.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1074706855/PMDpic32SPI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"PIC32Libs/bsp" -I"PIC32Libs/framework" -I"PIC32Libs/periph" -I"PIC32Libs" -I"C-Motion/Include" -I"." -MMD -MF "${OBJECTDIR}/_ext/1074706855/PMDpic32SPI.o.d" -o ${OBJECTDIR}/_ext/1074706855/PMDpic32SPI.o ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDpic32SPI.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1074706855/PMDsys.o: ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDsys.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1074706855" 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDsys.o.d 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDsys.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1074706855/PMDsys.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"PIC32Libs/bsp" -I"PIC32Libs/framework" -I"PIC32Libs/periph" -I"PIC32Libs" -I"C-Motion/Include" -I"." -MMD -MF "${OBJECTDIR}/_ext/1074706855/PMDsys.o.d" -o ${OBJECTDIR}/_ext/1074706855/PMDsys.o ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDsys.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1074706855/PMDtrans.o: ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDtrans.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1074706855" 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDtrans.o.d 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDtrans.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1074706855/PMDtrans.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"PIC32Libs/bsp" -I"PIC32Libs/framework" -I"PIC32Libs/periph" -I"PIC32Libs" -I"C-Motion/Include" -I"." -MMD -MF "${OBJECTDIR}/_ext/1074706855/PMDtrans.o.d" -o ${OBJECTDIR}/_ext/1074706855/PMDtrans.o ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDtrans.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1074706855/PMDutil.o: ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDutil.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1074706855" 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDutil.o.d 
	@${RM} ${OBJECTDIR}/_ext/1074706855/PMDutil.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1074706855/PMDutil.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"PIC32Libs/bsp" -I"PIC32Libs/framework" -I"PIC32Libs/periph" -I"PIC32Libs" -I"C-Motion/Include" -I"." -MMD -MF "${OBJECTDIR}/_ext/1074706855/PMDutil.o.d" -o ${OBJECTDIR}/_ext/1074706855/PMDutil.o ../PIC32Redux/PIC32Redux.X/C-Motion/C/PMDutil.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1738135402/DBPrint.o: ../PIC32Redux/PIC32Redux.X/DBPrint.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1738135402" 
	@${RM} ${OBJECTDIR}/_ext/1738135402/DBPrint.o.d 
	@${RM} ${OBJECTDIR}/_ext/1738135402/DBPrint.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1738135402/DBPrint.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"PIC32Libs/bsp" -I"PIC32Libs/framework" -I"PIC32Libs/periph" -I"PIC32Libs" -I"C-Motion/Include" -I"." -MMD -MF "${OBJECTDIR}/_ext/1738135402/DBPrint.o.d" -o ${OBJECTDIR}/_ext/1738135402/DBPrint.o ../PIC32Redux/PIC32Redux.X/DBPrint.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/PIC32Libs/ConfigBit.o: PIC32Libs/ConfigBit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/PIC32Libs" 
	@${RM} ${OBJECTDIR}/PIC32Libs/ConfigBit.o.d 
	@${RM} ${OBJECTDIR}/PIC32Libs/ConfigBit.o 
	@${FIXDEPS} "${OBJECTDIR}/PIC32Libs/ConfigBit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"PIC32Libs/bsp" -I"PIC32Libs/framework" -I"PIC32Libs/periph" -I"PIC32Libs" -I"C-Motion/Include" -I"." -MMD -MF "${OBJECTDIR}/PIC32Libs/ConfigBit.o.d" -o ${OBJECTDIR}/PIC32Libs/ConfigBit.o PIC32Libs/ConfigBit.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/PMDApp.o: PMDApp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PMDApp.o.d 
	@${RM} ${OBJECTDIR}/PMDApp.o 
	@${FIXDEPS} "${OBJECTDIR}/PMDApp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"PIC32Libs/bsp" -I"PIC32Libs/framework" -I"PIC32Libs/periph" -I"PIC32Libs" -I"C-Motion/Include" -I"." -MMD -MF "${OBJECTDIR}/PMDApp.o.d" -o ${OBJECTDIR}/PMDApp.o PMDApp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/PIC32SPI.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/PIC32SPI.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x37F   -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=500,--defsym=_min_stack_size=100,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/PIC32SPI.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/PIC32SPI.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=500,--defsym=_min_stack_size=100,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/PIC32SPI.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
