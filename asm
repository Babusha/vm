#!/usr/bin/ruby

#opcodes = {
#	"ip" => 0x0,
#	"ax" => 0x1,
#	"bx" => 0x2,
#	"cx" => 0x3,
#	"dx" => 0x4,
#	"ex" => 0x5,
#	"fx" => 0x6,
#	"bl" => 0x7,
#
#	"reg" => 0x1,
#	"dat" => 0x2,
#	"mem" => 0x3,
#	
#	"nop" => 0x0,
#	"inc" => 0x2,
#	"dec" => 0x3,
#	"add" => 0x4,
#	"sub" => 0x5,
#	"div" => 0x6,
#	"mul" => 0x7,
#	"mod" => 0x8,
#	"mov" => 0x9,
#
#	"call" => 0xA,
#	"ret" => 0xB,
#
#	"push" => 0x10,
#	"pop"  => 0x12,
#	"pusha" => 0x14,
#	"popa" => 0x15,
#
#	"and" => 0x16,
#	"or" => 0x17,
#	"xor" => 0x18,
#	"not" => 0x19,
#	"jmp" => 0x1A,
#	"jmpt" => 0x1B,
#	"jmpf" => 0x1C,
#
#	"loop" => 0x28,
#	"loopx" => 0x29,
#	"loope" => 0x2A,
#	"loopne" => 0x2B,
#	"loopnz" => 0x2C,
#	"loopz" => 0x2D,
#
#	"dump" => 0xFE,
#	"exit" => 0xFF,
#}

opcodes = {
	"ip" => 0x0,
	"ax" => 0x1,
	"bx" => 0x2,
	"cx" => 0x3,
	"dx" => 0x4,
	"ex" => 0x5,
	"fx" => 0x6,

	"byte" => 0x1,
	"word" => 0x2,
	"dword" => 0x4,
	"long" => 0x5,
	
	"reg" => 0x1,
	"dat" => 0x2,
	"ptr" => 0x3,

	"usig" => 0x0,
	"sig" => 0x1,
	"byte" => 0x1,
	"short" => 0x2,
	"int" => 0x3,
	"float" => 0x4,
	"string" => 0x5,
	"ptr" => 0x6,

	"usig_byte" => 0x0001,
	"sig_byte" => 0x0101,
	
	"array" => 0x7,

	"vm" => 0x0,
	"nop" => 0x0,
	"dump" => 0x1,
	"exit" => 0x2,

	"reg" => 0x1,
	"mov" => 0x1,
	"inc" => 0x2,
	"dec" => 0x3,

	"object" => 0x2,
	"new" => 0x1,
	"free" => 0x2,

}

def generate_header opcodes
	code = "# ifndef OPCODES_HPP\n# define OPCODES_HPP\n"
	opcodes.each do |opcode,value|
		code += "# \tdefine #{opcode.upcase} 0x#{value.to_s(16).upcase}\n"
	end
	code += "# endif"
end

if ARGV[0] == "-generate_opcodes"
	puts generate_header opcodes
	exit 0
end

ARGV.each do |path|
	if not File.exist? path
		puts "File #{path} doesn't exist"
		next
	end

	new_path = path.gsub '.asm','.bin'
	code = File.open(path,'r').readlines.join.split(" ")
	puts code.map { |opcode| opcodes[opcode.upcase] }.join
end

