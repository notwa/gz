local arg = {...}
if #arg < 1 then
  print("usage: `patch <rom-file>` " ..
       "(or drag and drop the rom file you wish to patch onto the patch script)")
  return
end
require("lua/rom_table")
for i = 1, #arg do
  print("patching `" .. arg[i] .. "`")
  local rom = gru.n64rom_load(arg[i])
  local rom_info = rawget(rom_table, rom:crc32())
  if rom_info == nil then
    error("unrecognized rom", 0)
  end
  local rom_id = rom_info.game .. "-" .. rom_info.version .. "-" .. rom_info.region
  local patch = gru.ups_load("ups/gz-" .. rom_id .. ".ups")
  patch:apply(rom)
  rom:save_file("gz-" .. rom_id ..  ".z64")
end
print("done")
