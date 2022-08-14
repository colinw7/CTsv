#ifndef CTsv_H
#define CTsv_H

#include <vector>
#include <string>

class CTsv {
 public:
  using Fields = std::vector<std::string>;
  using Data   = std::vector<Fields>;

 public:
  CTsv(const std::string &filename="");

  const std::string &filename() const { return filename_; }

  const Fields &header() const { return header_; }

  const Data &data() const { return data_; }

  bool isCommentHeader() const { return commentHeader_; }
  void setCommentHeader(bool b) { commentHeader_ = b; }

  bool isFirstLineHeader() const { return firstLineHeader_; }
  void setFirstLineHeader(bool b) { firstLineHeader_ = b; }

  bool isAllowEmpty() const { return allowEmpty_; }
  void setAllowEmpty(bool b) { allowEmpty_ = b; }

  bool load();

  bool stringToColumns(const std::string &str, Fields &columns);

 private:
  bool open() const;

  void close() const;

  bool isComment(const std::string &line, std::string &comment);

  bool readLine(std::string &line);

  bool stringToFields(const std::string &str, Fields &fields);

  void skipSpace(const std::string &str, int &i);

  void skipToTab(const std::string &str, int &i);

 private:
  std::string   filename_;
  Fields        header_;
  Data          data_;
  bool          commentHeader_   { true };
  bool          firstLineHeader_ { false };
  bool          allowEmpty_      { true };
  mutable FILE* fp_              { 0 };
};

#endif
