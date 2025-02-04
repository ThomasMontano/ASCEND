if(NOT "/home/udooer/Downloads/cmake-3.14.0-rc3/Tests/CMakeTests" MATCHES "^/")
  set(slash /)
endif()
set(url "file://${slash}/home/udooer/Downloads/cmake-3.14.0-rc3/Tests/CMakeTests/FileDownloadInput.png")
set(dir "/home/udooer/Downloads/cmake-3.14.0-rc3/Tests/CMakeTests/downloads")

message(STATUS "FileDownload:1")
file(DOWNLOAD
  ${url}
  ${dir}/file1.png
  TIMEOUT 2
  )

message(STATUS "FileDownload:2")
file(DOWNLOAD
  ${url}
  ${dir}/file2.png
  TIMEOUT 2
  SHOW_PROGRESS
  )

# Two calls in a row, exactly the same arguments.
# Since downloaded file should exist already for 2nd call,
# the 2nd call will short-circuit and return early...
#
if(EXISTS ${dir}/file3.png)
  file(REMOVE ${dir}/file3.png)
endif()

message(STATUS "FileDownload:3")
file(DOWNLOAD
  ${url}
  ${dir}/file3.png
  TIMEOUT 2
  EXPECTED_MD5 dbd330d52f4dbd60115d4191904ded92
  )

message(STATUS "FileDownload:4")
file(DOWNLOAD
  ${url}
  ${dir}/file3.png
  TIMEOUT 2
  STATUS status
  EXPECTED_HASH SHA1=67eee17f79d9ac557284fc0b8ad19f25723fb578
  )

message(STATUS "FileDownload:5")
file(DOWNLOAD
  ${url}
  ${dir}/file3.png
  TIMEOUT 2
  STATUS status
  EXPECTED_HASH SHA224=ba283726bbb602776818b463943189afd91836cb7ee5dd6e2c7b5ae4
  )

message(STATUS "FileDownload:6")
file(DOWNLOAD
  ${url}
  ${dir}/file3.png
  TIMEOUT 2
  STATUS status
  EXPECTED_HASH SHA256=cf3334b1275071e1da6e8c396ccb72cf1b2388d8c937526f3af26230affb9423
  )

message(STATUS "FileDownload:7")
file(DOWNLOAD
  ${url}
  ${dir}/file3.png
  TIMEOUT 2
  STATUS status
  EXPECTED_HASH SHA384=43a5d13978d97c660db44481aee0604cb4ff6ca0775cd5c2cd68cd8000e107e507c4caf6c228941231041e282ffb8950
  )

message(STATUS "FileDownload:8")
file(DOWNLOAD
  ${url}
  ${dir}/file3.png
  TIMEOUT 2
  STATUS status
  EXPECTED_HASH SHA512=6984e0909a1018030ccaa418e3be1654223cdccff0fe6adc745f9aea7e377f178be53b9fc7d54a6f81c2b62ef9ddcd38ba1978fedf4c5e7139baaf355eefad5b
  )
message(STATUS "FileDownload:9")
file(DOWNLOAD
  ${url}
  ${dir}/file3.png
  TIMEOUT 2
  STATUS status
  EXPECTED_HASH MD5=dbd330d52f4dbd60115d4191904ded92
  )

message(STATUS "FileDownload:10")
file(DOWNLOAD
  ${url}
  ${dir}/file3.png
  TIMEOUT 2
  STATUS status
  EXPECTED_MD5 dbd330d52f4dbd60115d4191904ded92
  )
message(STATUS "${status}")

message(STATUS "FileDownload:11")
file(DOWNLOAD
  badhostname.png
  ${dir}/file11.png
  TIMEOUT 2
  STATUS status
  )
message(STATUS "${status}")
list(GET status 0 status_code)
if(NOT ${status_code} EQUAL 6)
  message(SEND_ERROR "error: expected status code 6 for bad host name, got: ${status_code}")
endif()
