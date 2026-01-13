#include "pch.hpp"

#include "main.hpp"

namespace Experiment6 // read (fast_io), write and append (fstream)
{
	inline static std::string file_input_1 = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

	inline static std::string file_output_1 = "";

	inline static std::string file_input_2 = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

	inline static std::string file_output_2 = "";

	inline static std::string file_path_1 = "output_1.txt";

	inline static std::string file_path_2 = "output_2.txt";

	inline static fast_io::native_file fast_io_write_file(file_path_1, fast_io::open_mode::out);

	inline static fast_io::native_file fast_io_append_file(file_path_1, fast_io::open_mode::app);

	inline static fast_io::native_file_loader fast_io_read_file(file_path_1);

	inline static std::ofstream ofstream_write_file(file_path_2, std::ios::out);

	inline static std::ofstream ofstream_append_file(file_path_2, std::ios::app);

	inline static std::ifstream ifstream_read_file(file_path_2, std::ios::in);

	inline static std::fstream fstream_write_file(file_path_2, std::ios::out);

	inline static std::fstream fstream_append_file(file_path_2, std::ios::app);

	inline static std::fstream fstream_read_file(file_path_2, std::ios::in);

	inline static folly::File folly_write_file(file_path_1, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	inline static folly::File folly_append_file(file_path_1, O_WRONLY | O_CREAT | O_APPEND, 0644);

	inline static folly::File folly_read_file(file_path_1, O_RDONLY);

	inline static boost::iostreams::stream<boost::iostreams::file_sink> boost_write_file(
		file_path_1,
		std::ios::trunc
	);

	inline static boost::iostreams::stream<boost::iostreams::file_sink> boost_append_file(
		file_path_1,
		std::ios::app
	);

	inline static boost::iostreams::stream<boost::iostreams::file_source> boost_read_file(
		file_path_1
	);

	/*

	void libuv_file_write()
	{
		uv_loop_t* loop = uv_default_loop();
		uv_fs_t open_req;
		uv_fs_open(loop, &open_req, file_path_1.c_str(),
			O_WRONLY | O_CREAT | O_TRUNC, 0644, nullptr);

		if (open_req.result < 0)
		{
			return;
		}

		uv_file file = static_cast<uv_file>(open_req.result);
		uv_fs_req_cleanup(&open_req);

		uv_buf_t buf = uv_buf_init(const_cast<char*>(file_input_1.data()), file_input_1.size());
		uv_fs_t write_req;
		uv_fs_write(loop, &write_req, file, &buf, 1, 0, nullptr);
		uv_fs_req_cleanup(&write_req);

		uv_fs_t close_req;
		uv_fs_close(loop, &close_req, file, nullptr);
		uv_fs_req_cleanup(&close_req);
	}

	void libuv_file_append()
	{
		uv_loop_t* loop = uv_default_loop();
		uv_fs_t open_req;
		uv_fs_open(loop, &open_req, file_path_1.c_str(),
			O_WRONLY | O_CREAT | O_APPEND, 0644, nullptr);

		if (open_req.result < 0)
		{
			return;
		}

		uv_file file = static_cast<uv_file>(open_req.result);
		uv_fs_req_cleanup(&open_req);

		uv_buf_t buf = uv_buf_init(const_cast<char*>(file_input_1.data()), file_input_1.size());
		uv_fs_t write_req;
		uv_fs_write(loop, &write_req, file, &buf, 1, -1, nullptr);
		uv_fs_req_cleanup(&write_req);

		uv_fs_t close_req;
		uv_fs_close(loop, &close_req, file, nullptr);
		uv_fs_req_cleanup(&close_req);
	}

	void libuv_file_read()
	{
		uv_loop_t* loop = uv_default_loop();
		uv_fs_t open_req;
		uv_fs_open(loop, &open_req, file_path_1.c_str(), O_RDONLY, 0, nullptr);

		if (open_req.result < 0)
		{
			return;
		}

		uv_file file = static_cast<uv_file>(open_req.result);
		uv_fs_req_cleanup(&open_req);

		uv_fs_t stat_req;
		uv_fs_fstat(loop, &stat_req, file, nullptr);
		size_t size = stat_req.statbuf.st_size;
		uv_fs_req_cleanup(&stat_req);

		std::string data(size, '\0');
		uv_buf_t buf = uv_buf_init(data.data(), size);
		uv_fs_t read_req;
		uv_fs_read(loop, &read_req, file, &buf, 1, 0, nullptr);
		uv_fs_req_cleanup(&read_req);

		uv_fs_t close_req;
		uv_fs_close(loop, &close_req, file, nullptr);
		uv_fs_req_cleanup(&close_req);
	}

	*/ 
	void folly_file_write()
	{
		const char* buf = file_input_1.data();
		size_t remaining = file_input_1.size();
		while (remaining > 0)
		{
			int written = _write(folly_write_file.fd(), buf, static_cast<unsigned int>(remaining));
			if (written <= 0) break;
			remaining -= written;
			buf += written;
		}
	}

	void folly_file_append()
	{
		const char* buf = file_input_1.data();
		size_t remaining = file_input_1.size();
		while (remaining > 0)
		{
			int written = _write(folly_append_file.fd(), buf, static_cast<unsigned int>(remaining));
			if (written <= 0) break;
			remaining -= written;
			buf += written;
		}
	}

	void folly_file_read()
	{
		long size = _lseek(folly_read_file.fd(), 0, SEEK_END);
		_lseek(folly_read_file.fd(), 0, SEEK_SET);

		std::string buffer(size, '\0');
		char* buf = buffer.data();
		long remaining = size;

		while (remaining > 0)
		{
			int readBytes = _read(folly_read_file.fd(), buf, static_cast<unsigned int>(remaining));
			if (readBytes <= 0) break;
			remaining -= readBytes;
			buf += readBytes;
		}
	}

	void boost_file_write()
	{
		boost_write_file.write(file_input_1.data(), file_input_1.size());
		boost_write_file.flush();
	}

	void boost_file_append()
	{
		boost_append_file.write(file_input_1.data(), file_input_1.size());
		boost_append_file.flush();
	}

	void boost_file_read()
	{
		std::string output;

		boost_read_file.seekg(0, std::ios::end);
		output.resize(static_cast<size_t>(boost_read_file.tellg()));
		boost_read_file.seekg(0, std::ios::beg);
		boost_read_file.read(output.data(), output.size());
	}

	void fast_io_file_write()
	{
		fast_io::io::print(
			fast_io_write_file,
			file_input_1
		);

	}

	void fast_io_file_append()
	{
		fast_io::io::print(
			fast_io_append_file,
			file_input_1
		);
	}
	
	void fast_io_file_read()
	{
		std::string output
		{
			fast_io_read_file.begin(),
			fast_io_read_file.end()
		};
	}

	void ofstream_file_write()
	{
		ofstream_write_file << file_input_2;
	}

	void ofstream_file_append()
	{
		ofstream_append_file << file_input_2;
	}

	void ifstream_file_read()
	{
		ifstream_read_file >> file_output_2;
	}

	void fstream_file_write()
	{
		fstream_write_file << file_input_2;
	}

	void fstream_file_append()
	{
		fstream_append_file << file_input_2;
	}

	void fstream_file_read()
	{
		fstream_read_file >> file_output_2;
	}

	void before_test_case_iteration_callback()
	{
		file_output_1 = "";
		file_output_2 = "";

		ofstream_write_file.close();
		ofstream_append_file.close();
		ifstream_read_file.close();
		fstream_write_file.close();
		fstream_append_file.close();
		fstream_read_file.close();

		std::ofstream ofstream_write_file_temp_1(file_path_1, std::ios::out);
		ofstream_write_file_temp_1 << "";

		std::ofstream ofstream_write_file_temp_2(file_path_2, std::ios::out);
		ofstream_write_file_temp_2 << "";
	}

	void after_test_case_iteration_callback()
	{
		ofstream_write_file.close();
		ofstream_append_file.close();
		ifstream_read_file.close();
		fstream_write_file.close();
		fstream_append_file.close();
		fstream_read_file.close();

		std::ofstream ofstream_write_file_temp_1(file_path_1, std::ios::out);
		ofstream_write_file_temp_1 << "";

		std::ofstream ofstream_write_file_temp_2(file_path_2, std::ios::out);
		ofstream_write_file_temp_2 << "";
	}

	void execute()
	{
		NanobenchBenchmarkingTestSuite test_suite
		{
			.name = "file_io",
			.epoch_iteration_pairs =
			{
				{
					.epochs = 10'000,
					.iterations = 1
				},
				{
					.epochs = 1'000,
					.iterations = 10
				},
				{
					.epochs = 100,
					.iterations = 100
				},
				{
					.epochs = 10,
					.iterations = 1'000
				}

			},

			.test_cases =
			{
				{
					.name = "folly_file_write",
					.callback = folly_file_write
				},
				{
					.name = "folly_file_append",
					.callback = folly_file_append
				},
				{
					.name = "folly_file_read",
					.callback = folly_file_read,
					.before_test_callback = []()
					{
						std::ofstream ofstream_write_file_temp_1(file_path_1, std::ios::out);
						ofstream_write_file_temp_1 << "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
					}
				},
				{
					.name = "fast_io_file_write",
					.callback = fast_io_file_write
				},
				{
					.name = "fast_io_file_append",
					.callback = fast_io_file_append
				},
				{
					.name = "fast_io_file_read",
					.callback = fast_io_file_read,
					.before_test_callback = []()
					{
						std::ofstream ofstream_write_file_temp_1(file_path_1, std::ios::out);
						ofstream_write_file_temp_1 << "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
					}
				},
				{
					.name = "boost_file_write",
					.callback = boost_file_write
				},
				{
					.name = "boost_file_append",
					.callback = boost_file_append
				},
				{
					.name = "boost_file_read",
					.callback = boost_file_read,
					.before_test_callback = []()
					{
						std::ofstream ofstream_write_file_temp_1(file_path_1, std::ios::out);
						ofstream_write_file_temp_1 << "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
					}
				},
				{
					.name = "ofstream_file_write",
					.callback = ofstream_file_write
				},
				{
					.name = "ofstream_file_append",
					.callback = ofstream_file_append
				},
				{
					.name = "ifstream_file_read",
					.callback = ifstream_file_read,
					.before_test_callback = []()
					{
						std::ofstream ofstream_write_file_temp_2(file_path_2, std::ios::out);
						ofstream_write_file_temp_2 << "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
					}
				},
				{
					.name = "fstream_file_write",
					.callback = fstream_file_write
				},
				{
					.name = "fstream_file_append",
					.callback = fstream_file_append
				},
				{
					.name = "fstream_file_read",
					.callback = fstream_file_read,
					.before_test_callback = []()
					{
						std::ofstream ofstream_write_file_temp_2(file_path_2, std::ios::out);
						ofstream_write_file_temp_2 << "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
					}
				}
			},

			.before_test_case_iteration_callback =
				before_test_case_iteration_callback,

			.after_test_case_iteration_callback =
				after_test_case_iteration_callback

		};

		execute_nanobenchmark(
			test_suite
		);

		bool exit_code;
		std::cin >> exit_code;
	}
}

int main(int argc, char** argv)
{	
	Experiment6::execute();

    return 0;
}

namespace QLogicaeCppCoreBenchmark
{

}
