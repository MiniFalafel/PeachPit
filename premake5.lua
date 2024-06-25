-- This is the file that will be run by the setup file. It includes all needed premake files for all projects.

-- WORKSPACE
workspace "PeachPit"
	architecture "x86_64"
	startproject "sandbox"
	
	configurations
	{
		"DEBUG",
		"RELEASE",
		"DIST"
	}
	
-- binary directory

BIN_DIR = "%{cfg.buildcfg}-%{cfg.architecture}"

-- PROJECTS
include "peachpit/peachpit"
include "sandbox/sandbox"