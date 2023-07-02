In the past, I used Conan for C++ packaging. However, lately I am just using this project as a submodule instead.

I cannot find a way to have the unit tests run without error, and successfully build CompleteControl while it uses this project.
The only way I know of, atm, is to remove this while running unit tests:
	<ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">
		<ClCompile>
			...
			<RuntimeLibrary>MultiThreadedDebug</RuntimeLibrary>
		</ClCompile>
		...
	</ItemDefinitionGroup>
