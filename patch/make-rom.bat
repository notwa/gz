@echo off
pushd .
cd %~dp0/..
gru patch/lua/make-rom.lua %*
popd
