# Pull Request Template

## PR Title (delete this part after completing PR title)

> **Only use Example title for multiple commits**
> branch-name: Add ...
>
> **Only use Example title for one commit (this is your commit message)**
> tst: [dev #00] add blank.yml: Read description

## Type of change
- [x] Bug fix (non-breaking change which fixes an issue)
- [ ] New feature (non-breaking change which adds functionality)
- [ ] Breaking change (fix or feature that would cause existing functionality to not work as expected)
- [x] This change requires a documentation update

## Fix
This pull request fixes #00 (issue) from discussion #...

## Changes
**File-name**: [ commit SHA-1 hash ] *commit message 1*
> commit description

**File-name**: [ commit SHA-1 hash ] *commit message 1*
> commit description

## Quality Assurance Checklist:
**Test**
> Please describe the tests that you ran to verify your changes. Provide instructions so we can reproduce. Please also list any relevant details for your test configuration

- [x] No test required: skipped **OS Test Configuration**
- [ ] Test A
- [ ] Test B
- [ ] Test C

**Windows OS Test Configuration** (delete if not used)
> use `systeminfo` for Windows, then fill out the following fields.

* Software version:
   - [ **OS Name**: `Microsoft Windows 11 Home` ]
   - [ **OS Version**: `10.0.22000 N/A Build 22000` ]
* Firmware version: 
   - [ **BIOS Version**: `Razer 1.03, 8/3/2021` ]
* Hardware version:
   - [ **System Model**: `Blade 15 Base Model (Mid 2021) - RZ09-0410` ]
   - [ **System Type**: `x64-based PC` ]
   - [ **Processor(s)**: `Intel64 Family 6 Model 141 Stepping 1 GenuineIntel ~2304 Mhz` ]
* Build system:
	- [ **cmake** ]
* SDK:
	- [ N/A ]

**macOS Test Configuration**: (delete if not used)
> use `systeminfo` for Windows, then fill out the following fields.

* Software version:
	- [ **OS Name**: `..` ]
	- [ **OS Version**: `..` ]
* Firmware version:
	- [ **BIOS Version**: `..` ]
* Hardware version:
	- [ **System Model**: `..` ]
	- [ **System Type**: `..` ]
	- [ **Processor(s)**: `..` ]
* Build system:
	- [ **cmake** ]
* SDK:
	- [ N/A ]

**Linux OS Test Configuration**: (delete if not used)
> use `systeminfo` for Windows, then fill out the following fields.

* Software version:
	- [ **OS Name**: `..` ]
	- [ **OS Version**: `..` ]
* Firmware version:
	- [ **BIOS Version**: `..` ]
* Hardware version:
	- [ **System Model**: `..` ]
	- [ **System Type**: `..` ]
	- [ **Processor(s)**: `..` ]
* Build system:
	- [ **cmake** ]
* SDK:
	- [ N/A ]

**Android OS Test Configuration**: (delete if not used)
> use `systeminfo` for Windows, then fill out the following fields.

* Software version:
	- [ **OS Name**: `..` ]
	- [ **OS Version**: `..` ]
* Firmware version:
	- [ **BIOS Version**: `..` ]
* Hardware version:
	- [ **System Model**: `..` ]
	- [ **System Type**: `..` ]
	- [ **Processor(s)**: `..` ]
* Build system:
	- [ **cmake** ]
* SDK:
	- [ N/A ]

## Checklist:
- [x] I have performed a self-review of my own code
- [ ] I have commented on my code, particularly in hard-to-understand areas
- [ ] My changes generate no new warnings
- [ ] I have checked my code and corrected any misspellings
