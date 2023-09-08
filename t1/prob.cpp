
int max_chunk_index = -1;
int deleted_chunk_count = 0;
int create_delete_count = 0;
unsigned __int64 num = 0, nm = 0;
int sign = 0;

struct ChunkInfo {
	int size;
	// int padding;
	__int64* data;
};

std::vector<ChunkInfo> chunk_infos;

void create(int size, int type) {
	assert(create_delete_count < 16);
	create_delete_count++;

	assert(deleted_chunk_count + max_chunk_index < 14);
	assert(0x10 <= size < 0x100);
	max_chunk_index++;
	chunk_infos[max_chunk_index].size = size;
	chunk_infos[max_chunk_index].data = (__int64*) malloc(size);
	if (type == 1) {
		num = chunk_infos[max_chunk_index].data[0];
	} else if (type == 2) {
		chunk_infos[max_chunk_index].data[0] = num;
	} else {
		assert(type == 0);
		// nop
	}
}

void remake(unsigned int index, int new_size, int type) {
	assert(sign == 0);
	sign = 1;

	assert(index <= (unsigned int) max_chunk_index);
	chunk_infos[index].size = new_size;
	chunk_infos[index].data = (__int64*) malloc(new_size);
	if (type == 1) {
		num = chunk_infos[index].data[0];
	} else if (type == 2) {
		chunk_infos[index].data[0] = num;
	} else {
		assert(type == 0);
		// nop
	}
}

void delete(unsigned int index) {
	assert(create_delete_count < 16);
	create_delete_count++;

	assert(index <= (unsigned int) max_chunk_index);
	assert(chunk_infos[index].data and chunk_infos[index].size);

	if (0 <= index < 15) {
		// std::vector<ChunkInfo>::erase
		memcpy(&chunk_infos[index], &chunk_infos[index + 1], (14 - index) * sizeof(ChunkInfo));
		chunk_infos[14].size = 0;
		chunk_infos[14].data = 0;
	} else {
		chunk_infos[index].size = 0;
		chunk_infos[index].data = 0;
	}
	--max_chunk_index;
	++deleted_chunk_count;
}

void add(unsigned int value) {
	num += value;
}
void sub(unsigned int value) {
	if (value > num) value = 0;
	num -= value;
}

void and(unsigned int value) {
	if (value == 1) num &= nm;
	else num &= value;
}

void  or(unsigned int value) {
	if (value == 0) num |= nm;
	else num |= value;
}

void  xor(unsigned int value) {
	if (value == 0) num ^= nm;
	else num ^= value;
}

void swap() {
	unsigned __int64 tmp = num;
	num = nm;
	nm = tmp;
}

int _end = 0;
void end() {
	_end = 1;
}

void KCTF() {
	// operations

	end();
}

int main() {
	for (int i = 0; i < 15; i++) {
		chunk_infos.push_back(ChunkInfo(0, NULL));
	}

	// operations
	KCTF();
	// end
	return _end;
}