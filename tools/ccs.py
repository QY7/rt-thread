import os
import re
from string import Template

import rtconfig
import shutil
import time

# version
MODULE_VER_NUM = 1

cproject_temp = """<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<?fileVersion 4.0.0?><cproject storage_type_id="org.eclipse.cdt.core.XmlProjectDescriptionStorage">
	<storageModule configRelations="2" moduleId="org.eclipse.cdt.core.settings">
		<cconfiguration id="com.ti.ccstudio.buildDefinitions.C2000.Debug.1821767246.1625729396">
			<storageModule buildSystemId="org.eclipse.cdt.managedbuilder.core.configurationDataProvider" id="com.ti.ccstudio.buildDefinitions.C2000.Debug.1821767246.1625729396" moduleId="org.eclipse.cdt.core.settings" name="RAM">
				<externalSettings/>
				<extensions>
					<extension id="com.ti.ccstudio.binaryparser.CoffParser" point="org.eclipse.cdt.core.BinaryParser"/>
					<extension id="org.eclipse.cdt.core.GmakeErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
					<extension id="com.ti.ccstudio.errorparser.CoffErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
					<extension id="com.ti.ccstudio.errorparser.AsmErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
					<extension id="com.ti.ccstudio.errorparser.LinkErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
				</extensions>
			</storageModule>
			<storageModule moduleId="cdtBuildSystem" version="4.0.0">
				<configuration artifactExtension="out" artifactName="${ProjName}" buildProperties="" cleanCommand="${CG_CLEAN_CMD}" description="" id="com.ti.ccstudio.buildDefinitions.C2000.Debug.1821767246.1625729396" name="RAM" parent="com.ti.ccstudio.buildDefinitions.C2000.Debug">
					<folderInfo id="com.ti.ccstudio.buildDefinitions.C2000.Debug.1821767246.1625729396." name="/" resourcePath="">
						<toolChain id="com.ti.ccstudio.buildDefinitions.C2000_20.2.exe.DebugToolchain.805031189" name="TI Build Tools" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.exe.DebugToolchain" targetTool="com.ti.ccstudio.buildDefinitions.C2000_20.2.exe.linkerDebug.1620918859">
							<option IS_BUILTIN_EMPTY="false" IS_VALUE_EMPTY="false" id="com.ti.ccstudio.buildDefinitions.core.OPT_TAGS.866428047" superClass="com.ti.ccstudio.buildDefinitions.core.OPT_TAGS" valueType="stringList">
								<listOptionValue builtIn="false" value="DEVICE_CONFIGURATION_ID=TMS320C28XX.TMS320F28379D"/>
								<listOptionValue builtIn="false" value="DEVICE_CORE_ID="/>
								<listOptionValue builtIn="false" value="DEVICE_ENDIANNESS=little"/>
								<listOptionValue builtIn="false" value="OUTPUT_FORMAT=ELF"/>
								<listOptionValue builtIn="false" value="LINKER_COMMAND_FILE=2837x_RAM_lnk_cpu1.cmd"/>
								<listOptionValue builtIn="false" value="RUNTIME_SUPPORT_LIBRARY=libc.a"/>
								<listOptionValue builtIn="false" value="CCS_MBS_VERSION=6.1.3"/>
								<listOptionValue builtIn="false" value="PRODUCTS="/>
								<listOptionValue builtIn="false" value="PRODUCT_MACRO_IMPORTS={}"/>
								<listOptionValue builtIn="false" value="OUTPUT_TYPE=executable"/>
							</option>
							<option id="com.ti.ccstudio.buildDefinitions.core.OPT_CODEGEN_VERSION.1297229691" superClass="com.ti.ccstudio.buildDefinitions.core.OPT_CODEGEN_VERSION" value="20.2.5.LTS" valueType="string"/>
							<targetPlatform id="com.ti.ccstudio.buildDefinitions.C2000_20.2.exe.targetPlatformDebug.1087687528" name="Platform" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.exe.targetPlatformDebug"/>
							<builder buildPath="${BuildDirectory}" id="com.ti.ccstudio.buildDefinitions.C2000_20.2.exe.builderDebug.1955411756" name="GNU Make.RAM" parallelBuildOn="true" parallelizationNumber="optimal" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.exe.builderDebug"/>
							<tool id="com.ti.ccstudio.buildDefinitions.C2000_20.2.exe.compilerDebug.390186039" name="C2000 Compiler" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.exe.compilerDebug">
								<option id="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.LARGE_MEMORY_MODEL.1570013546" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.LARGE_MEMORY_MODEL" value="true" valueType="boolean"/>
								<option id="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.UNIFIED_MEMORY.1676451163" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.UNIFIED_MEMORY" value="true" valueType="boolean"/>
								<option id="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.SILICON_VERSION.1349230367" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.SILICON_VERSION" value="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.SILICON_VERSION.28" valueType="enumerated"/>
								<option id="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.FLOAT_SUPPORT.1882522149" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.FLOAT_SUPPORT" value="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.FLOAT_SUPPORT.softlib" valueType="enumerated"/>
								<option id="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.CLA_SUPPORT.1345954516" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.CLA_SUPPORT" value="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.CLA_SUPPORT.cla1" valueType="enumerated"/>
								<option id="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.VCU_SUPPORT.1732478382" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.VCU_SUPPORT" value="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.VCU_SUPPORT.vcu2" valueType="enumerated"/>
								<option id="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.TMU_SUPPORT.799806461" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.TMU_SUPPORT" value="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.TMU_SUPPORT.tmu0" valueType="enumerated"/>
								<option IS_BUILTIN_EMPTY="false" IS_VALUE_EMPTY="false" id="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.INCLUDE_PATH.327828185" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.INCLUDE_PATH" valueType="includePath">
									<listOptionValue builtIn="false" value="${PROJECT_ROOT}"/>
									<listOptionValue builtIn="false" value="${PROJECT_ROOT}/../libraries/HAL_Drivers"/>
									<listOptionValue builtIn="false" value="${PROJECT_ROOT}/board"/>
									<listOptionValue builtIn="false" value="${PROJECT_LOC}/../../../../components/finsh"/>
									<listOptionValue builtIn="false" value="${PROJECT_LOC}/../../../../components/drivers/include"/>
									<listOptionValue builtIn="false" value="${PROJECT_LOC}/../libraries/tms320f28379d/headers/include"/>
									<listOptionValue builtIn="false" value="${PROJECT_LOC}/../libraries/tms320f28379d/common/include"/>
									<listOptionValue builtIn="false" value="${PROJECT_LOC}/../../../../include"/>
									<listOptionValue builtIn="false" value="${PROJECT_LOC}/../../../../src"/>
									<listOptionValue builtIn="false" value="${PROJECT_LOC}/../libraries/HAL_Drivers/config"/>
									<listOptionValue builtIn="false" value="${PROJECT_LOC}/../libraries/HAL_Drivers"/>
									<listOptionValue builtIn="false" value="${CG_TOOL_ROOT}/include"/>
								</option>
								<option id="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.ADVICE__PERFORMANCE.830431972" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.ADVICE__PERFORMANCE" value="--advice:performance=all" valueType="string"/>
								<option IS_BUILTIN_EMPTY="false" IS_VALUE_EMPTY="false" id="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.DEFINE.2020324398" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.DEFINE" valueType="definedSymbols">
									<listOptionValue builtIn="false" value="CPU1"/>
									<listOptionValue builtIn="false" value="_RAM"/>
									<listOptionValue builtIn="false" value="_LAUNCHXL_F28379D"/>
									<listOptionValue builtIn="false" value="RT_USING_LIBC"/>
								</option>
								<option id="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.DEBUGGING_MODEL.275881916" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.DEBUGGING_MODEL" value="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.DEBUGGING_MODEL.SYMDEBUG__DWARF" valueType="enumerated"/>
								<option IS_BUILTIN_EMPTY="false" IS_VALUE_EMPTY="false" id="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.DIAG_WARNING.515724194" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.DIAG_WARNING" valueType="stringList">
									<listOptionValue builtIn="false" value="225"/>
								</option>
								<option id="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.DIAG_WRAP.1176414858" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.DIAG_WRAP" value="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.DIAG_WRAP.off" valueType="enumerated"/>
								<option id="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.DISPLAY_ERROR_NUMBER.739081775" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.DISPLAY_ERROR_NUMBER" value="true" valueType="boolean"/>
								<option id="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.ABI.1808710570" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.ABI" value="com.ti.ccstudio.buildDefinitions.C2000_20.2.compilerID.ABI.eabi" valueType="enumerated"/>
								<inputType id="com.ti.ccstudio.buildDefinitions.C2000_20.2.compiler.inputType__C_SRCS.671334842" name="C Sources" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.compiler.inputType__C_SRCS"/>
								<inputType id="com.ti.ccstudio.buildDefinitions.C2000_20.2.compiler.inputType__CPP_SRCS.1423480404" name="C++ Sources" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.compiler.inputType__CPP_SRCS"/>
								<inputType id="com.ti.ccstudio.buildDefinitions.C2000_20.2.compiler.inputType__ASM_SRCS.379818063" name="Assembly Sources" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.compiler.inputType__ASM_SRCS"/>
								<inputType id="com.ti.ccstudio.buildDefinitions.C2000_20.2.compiler.inputType__ASM2_SRCS.1234298596" name="Assembly Sources" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.compiler.inputType__ASM2_SRCS"/>
							</tool>
							<tool id="com.ti.ccstudio.buildDefinitions.C2000_20.2.exe.linkerDebug.1620918859" name="C2000 Linker" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.exe.linkerDebug">
								<option id="com.ti.ccstudio.buildDefinitions.C2000_20.2.linkerID.STACK_SIZE.508710445" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.linkerID.STACK_SIZE" value="0x100" valueType="string"/>
								<option id="com.ti.ccstudio.buildDefinitions.C2000_20.2.linkerID.MAP_FILE.1988848580" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.linkerID.MAP_FILE" value="${ProjName}.map" valueType="string"/>
								<option id="com.ti.ccstudio.buildDefinitions.C2000_20.2.linkerID.OUTPUT_FILE.1523670563" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.linkerID.OUTPUT_FILE" value="${ProjName}.out" valueType="string"/>
								<option id="com.ti.ccstudio.buildDefinitions.C2000_20.2.linkerID.HEAP_SIZE.1888683655" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.linkerID.HEAP_SIZE" value="0x100" valueType="string"/>
								<option IS_BUILTIN_EMPTY="false" IS_VALUE_EMPTY="false" id="com.ti.ccstudio.buildDefinitions.C2000_20.2.linkerID.LIBRARY.70117125" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.linkerID.LIBRARY" valueType="libs">
									<listOptionValue builtIn="false" value="libc.a"/>
								</option>
								<option IS_BUILTIN_EMPTY="false" IS_VALUE_EMPTY="false" id="com.ti.ccstudio.buildDefinitions.C2000_20.2.linkerID.SEARCH_PATH.1118756245" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.linkerID.SEARCH_PATH" valueType="libPaths">
									<listOptionValue builtIn="false" value="${CG_TOOL_ROOT}/lib"/>
									<listOptionValue builtIn="false" value="${CG_TOOL_ROOT}/include"/>
								</option>
								<option id="com.ti.ccstudio.buildDefinitions.C2000_20.2.linkerID.DIAG_WRAP.139679083" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.linkerID.DIAG_WRAP" value="com.ti.ccstudio.buildDefinitions.C2000_20.2.linkerID.DIAG_WRAP.off" valueType="enumerated"/>
								<option id="com.ti.ccstudio.buildDefinitions.C2000_20.2.linkerID.DISPLAY_ERROR_NUMBER.1524425632" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.linkerID.DISPLAY_ERROR_NUMBER" value="true" valueType="boolean"/>
								<option id="com.ti.ccstudio.buildDefinitions.C2000_20.2.linkerID.XML_LINK_INFO.1099703323" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.linkerID.XML_LINK_INFO" value="${ProjName}_linkInfo.xml" valueType="string"/>
								<option IS_BUILTIN_EMPTY="false" IS_VALUE_EMPTY="false" id="com.ti.ccstudio.buildDefinitions.C2000_20.2.linkerID.OTHER_FLAGS.1318472806" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.linkerID.OTHER_FLAGS" valueType="stringList">
									<listOptionValue builtIn="false" value=""/>
								</option>
								<inputType id="com.ti.ccstudio.buildDefinitions.C2000_20.2.exeLinker.inputType__CMD_SRCS.948473806" name="Linker Command Files" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.exeLinker.inputType__CMD_SRCS"/>
								<inputType id="com.ti.ccstudio.buildDefinitions.C2000_20.2.exeLinker.inputType__CMD2_SRCS.1762886200" name="Linker Command Files" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.exeLinker.inputType__CMD2_SRCS"/>
								<inputType id="com.ti.ccstudio.buildDefinitions.C2000_20.2.exeLinker.inputType__GEN_CMDS.2045947623" name="Generated Linker Command Files" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.exeLinker.inputType__GEN_CMDS"/>
							</tool>
							<tool id="com.ti.ccstudio.buildDefinitions.C2000_20.2.hex.1938108307" name="C2000 Hex Utility" superClass="com.ti.ccstudio.buildDefinitions.C2000_20.2.hex"/>
						</toolChain>
					</folderInfo>
					<sourceEntries>
						<entry excluding="|" flags="VALUE_WORKSPACE_PATH|RESOLVED" kind="sourcePath" name=""/>
					</sourceEntries>
				</configuration>
			</storageModule>
			<storageModule moduleId="org.eclipse.cdt.core.externalSettings"/>
		</cconfiguration>
	</storageModule>
	<storageModule moduleId="org.eclipse.cdt.core.LanguageSettingsProviders"/>
	<storageModule moduleId="org.eclipse.cdt.core.language.mapping">
		<project-mappings>
			<content-type-mapping configuration="" content-type="org.eclipse.cdt.core.asmSource" language="com.ti.ccstudio.core.TIASMLanguage"/>
			<content-type-mapping configuration="" content-type="org.eclipse.cdt.core.cHeader" language="com.ti.ccstudio.core.TIGCCLanguage"/>
			<content-type-mapping configuration="" content-type="org.eclipse.cdt.core.cSource" language="com.ti.ccstudio.core.TIGCCLanguage"/>
			<content-type-mapping configuration="" content-type="org.eclipse.cdt.core.cxxHeader" language="com.ti.ccstudio.core.TIGPPLanguage"/>
			<content-type-mapping configuration="" content-type="org.eclipse.cdt.core.cxxSource" language="com.ti.ccstudio.core.TIGPPLanguage"/>
		</project-mappings>
	</storageModule>
	<storageModule moduleId="org.eclipse.cdt.core.pathentry"/>
	<storageModule moduleId="cdtBuildSystem" version="4.0.0">
		<project id="rt-thread.com.ti.ccstudio.buildDefinitions.C2000.ProjectType.1837437567" name="C2000" projectType="com.ti.ccstudio.buildDefinitions.C2000.ProjectType"/>
	</storageModule>
	<storageModule moduleId="org.eclipse.cdt.make.core.buildtargets"/>
	<storageModule moduleId="scannerConfiguration"/>
</cproject>
"""

project_temp = """<?xml version="1.0" encoding="UTF-8"?>
<projectDescription>
    <name>__project_name_flag__</name>
    <comment></comment>
    <projects>
    </projects>
    <buildSpec>
        <buildCommand>
            <name>org.eclipse.cdt.managedbuilder.core.genmakebuilder</name>
            <triggers>clean,full,incremental,</triggers>
            <arguments>
            </arguments>
        </buildCommand>
        <buildCommand>
            <name>org.eclipse.cdt.managedbuilder.core.ScannerConfigBuilder</name>
            <triggers>full,incremental,</triggers>
            <arguments>
            </arguments>
        </buildCommand>
    </buildSpec>
    <natures>
        <nature>org.eclipse.cdt.core.cnature</nature>
        <nature>org.rt-thread.studio.rttnature</nature>
        <nature>org.eclipse.cdt.managedbuilder.core.managedBuildNature</nature>
        <nature>org.eclipse.cdt.managedbuilder.core.ScannerConfigNature</nature>
    </natures>
</projectDescription>"""

projcfg_ini_temp = """#RT-Thread Studio Project Configuration
# $time
cfg_version=v3.0

board_name=
bsp_version=
bsp_path=
chip_name=
project_base_rtt_bsp=true
is_use_scons_build=true
hardware_adapter=
selected_rtt_version=latest
board_base_nano_proj=false
is_base_example_project=false
example_name=
project_type=rt-thread
os_branch=master
os_version=latest
project_name=$project_name
output_project_path=$output_project_path"""

eclipse_core_runtime_temp = """content-types/enabled=true
content-types/org.eclipse.cdt.core.asmSource/file-extensions=s
eclipse.preferences.version=1"""

makefile_targets_temp = """clean2:
\t-$(RM) $(CC_DEPS)$(C++_DEPS)$(C_UPPER_DEPS)$(CXX_DEPS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS)$(CPP_DEPS)
\t-$(RM) $(OBJS) *.elf
\t-@echo ' '

*.elf: $(wildcard ../linkscripts/*/*.lds) $(wildcard ../linkscripts/*/*/*.lds)"""


def get_mcu_info(uvproj_file_path):
    if os.path.exists(uvproj_file_path):
        with open(uvproj_file_path, mode='r') as f:
            data = f.read()
            result = re.search("<Device>(.*)</Device>", data)
            if result:
                return result.group(1)
            else:
                return "unknown"
    else:
        return "unknown"


def gen_makefile_targets(output_file_path):
    try:
        w_str = makefile_targets_temp
        dir_name = os.path.dirname(output_file_path)
        if not os.path.exists(dir_name):
            os.makedirs(dir_name)
        with open(output_file_path, 'w') as f:
            f.write(w_str)
            return True
    except Exception as e:
        print(e)
        return False


def gen_org_eclipse_core_runtime_prefs(output_file_path):
    try:
        w_str = eclipse_core_runtime_temp
        dir_name = os.path.dirname(output_file_path)
        if not os.path.exists(dir_name):
            os.makedirs(dir_name)
        with open(output_file_path, 'w') as f:
            f.write(w_str)
            return True
    except Exception as e:
        print(e)
        return False


def gen_cproject_file(output_file_path):
    template_file_path = os.path.join(os.path.dirname(output_file_path), "template.cproject")
    if os.path.exists(template_file_path):
        try:
            shutil.copy(template_file_path, output_file_path)
        except Exception as e:
            print(e)
        return True
    else:
        CFLAGS = rtconfig.CFLAGS
        AFLAGS = rtconfig.AFLAGS
        LFLAGS = rtconfig.LFLAGS
        if 'CXXFLAGS' in dir(rtconfig):
            CXXFLAGS = rtconfig.CXXFLAGS
        else:
            CXXFLAGS = ""

        if "-T" in LFLAGS:
            items = str(LFLAGS).split()
            t_index = items.index("-T")
            items[t_index] = ""
            items[t_index + 1] = ""
            LFLAGS = " ".join(items)

        try:
            w_str = cproject_temp
            if "a_misc_flag" in w_str:
                w_str = w_str.replace("a_misc_flag", AFLAGS)
            if "c_misc_flag" in w_str:
                w_str = w_str.replace("c_misc_flag", CFLAGS)
            if "cpp_misc_flag" in w_str:
                w_str = w_str.replace("cpp_misc_flag", CXXFLAGS)
            if "c_link_misc_flag" in w_str:
                w_str = w_str.replace("c_link_misc_flag", LFLAGS)
            if "cpp_link_misc_flag" in w_str:
                w_str = w_str.replace("cpp_link_misc_flag", LFLAGS)

            dir_name = os.path.dirname(output_file_path)
            if not os.path.exists(dir_name):
                os.makedirs(dir_name)
            with open(output_file_path, 'w') as f:
                f.write(w_str)
                return True
        except Exception as e:
            return False


def gen_project_file(output_file_path):
    try:
        w_str = project_temp
        dir_name = os.path.dirname(output_file_path)
        if not os.path.exists(dir_name):
            os.makedirs(dir_name)
        with open(output_file_path, 'w') as f:
            f.write(w_str)
            return True
    except Exception as e:
        return False


def gen_projcfg_ini_file(chip_name, project_name, output_file_path):
    try:
        projcfg_file_tmp = Template(projcfg_ini_temp)
        w_str = projcfg_file_tmp.substitute(time=time.strftime("%a %b %d %H:%M:%S %Y", time.localtime()),
                                            project_name=project_name,
                                            output_project_path=os.path.abspath(""))
        dir_name = os.path.dirname(output_file_path)
        if not os.path.exists(dir_name):
            os.makedirs(dir_name)
        with open(output_file_path, 'w') as f:
            f.write(w_str)
            return True
    except Exception as e:
        return False
