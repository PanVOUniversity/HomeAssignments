/*Pan Vladimir st128934@student.spbu.ru
"Home assignment 5 - virtual methods creation and use*/
// TransformerTest.cpp
#include <gtest/gtest.h>
#include "City.h"
#include "Transformer.h"
#include "Advantage.h"
#include "Autobot.h"
#include "Minicon.h"
#include "Decepticon.h"
#include <vector>

TEST(TransformerTest, TransformOutput) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Transformer transformer;
    transformer.transform();

    std::cout.rdbuf(originalBuffer);

    EXPECT_EQ(capturedOutput.str(), "Default constructor called.\nTransformer, transform\n");
}

TEST(TransformerTest, UltaOutput) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Transformer transformer;
    transformer.ulta();

    std::cout.rdbuf(originalBuffer);

    EXPECT_EQ(capturedOutput.str(), "Default constructor called.\nTransformer, ulta\n");
}

TEST(TransformerTest, OpenFireOutput) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Transformer transformer;
    transformer.openFire();

    std::cout.rdbuf(originalBuffer);

    EXPECT_EQ(capturedOutput.str(), "Default constructor called.\nTransformer, openFire\n");
}

TEST(DecepticonTest, TransformOutput) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Decepticon decepticon;
    decepticon.transform();

    std::cout.rdbuf(originalBuffer);

    EXPECT_EQ(capturedOutput.str(), "Decepticon, transform\n");
}

TEST(DecepticonTest, UltaOutput) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Decepticon decepticon;
    decepticon.ulta();

    std::cout.rdbuf(originalBuffer);

    EXPECT_EQ(capturedOutput.str(), "Decepticon, ulta\n");
}

TEST(DecepticonTest, OpenFireOutput) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Decepticon decepticon;
    decepticon.openFire();

    std::cout.rdbuf(originalBuffer);

    EXPECT_EQ(capturedOutput.str(), "Decepticon, openFire\n");
}

TEST(AutobotTest, CallCommanderOutput) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Autobot autobot("Autobot1", 100, 50, 10, "Optimus Prime", "To protect humanity");
    autobot.callComander();

    std::cout.rdbuf(originalBuffer);

    EXPECT_EQ(capturedOutput.str(), "Optimus Prime!!!\n");
}

TEST(AutobotTest, TransformOutput) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Autobot autobot;
    autobot.transform();

    std::cout.rdbuf(originalBuffer);

    EXPECT_EQ(capturedOutput.str(), "Autobot, transform\n");
}

TEST(AutobotTest, UltaOutput) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Autobot autobot;
    autobot.ulta();

    std::cout.rdbuf(originalBuffer);

    EXPECT_EQ(capturedOutput.str(), "Autobot, ulta\n");
}

TEST(AutobotTest, OpenFireOutput) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Autobot autobot;
    autobot.openFire();

    std::cout.rdbuf(originalBuffer);

    EXPECT_EQ(capturedOutput.str(), "Autobot, openFire\n");
}


TEST(AutobotTest, TransformWithBasePointer) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Transformer* autobot = new Autobot();
    autobot->transform();

    std::cout.rdbuf(originalBuffer);
    

    EXPECT_EQ(capturedOutput.str(), "Autobot, transform\n");
}

TEST(AutobotTest, UltaWithBasePointer) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Transformer* autobot = new Autobot();
    autobot->ulta();

    std::cout.rdbuf(originalBuffer);
    

    EXPECT_EQ(capturedOutput.str(), "Autobot, ulta\n");
}

TEST(AutobotTest, OpenFireWithBasePointer) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Transformer* autobot = new Autobot();
    autobot->openFire();

    std::cout.rdbuf(originalBuffer);
    

    EXPECT_EQ(capturedOutput.str(), "Autobot, openFire\n");
}

TEST(DecepticonTest, TransformWithBasePointer) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Transformer* decepticon = new Decepticon();
    decepticon->transform();

    std::cout.rdbuf(originalBuffer);
    

    EXPECT_EQ(capturedOutput.str(), "Decepticon, transform\n");
}

TEST(DecepticonTest, UltaWithBasePointer) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Transformer* decepticon = new Decepticon();
    decepticon->ulta();

    std::cout.rdbuf(originalBuffer);
    

    EXPECT_EQ(capturedOutput.str(), "Decepticon, ulta\n");
}

TEST(DecepticonTest, OpenFireWithBasePointer) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Transformer* decepticon = new Decepticon();
    decepticon->openFire();

    std::cout.rdbuf(originalBuffer);
    

    EXPECT_EQ(capturedOutput.str(), "Decepticon, openFire\n");
}


TEST(TransformerTest, VirtualMethodCalls) {
    std::vector<Transformer*> transformers;

    transformers.push_back(new Autobot());
    transformers.push_back(new Autobot());
    transformers.push_back(new Autobot());

    transformers.push_back(new Decepticon());
    transformers.push_back(new Decepticon());
    transformers.push_back(new Decepticon());

    transformers.push_back(new Transformer());
    transformers.push_back(new Transformer());
    transformers.push_back(new Transformer());

    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    for (auto& transformer : transformers) {
        transformer->transform();
        transformer->ulta();
        transformer->openFire();
    }

    std::cout.rdbuf(originalBuffer);

    EXPECT_TRUE(capturedOutput.str().find("Autobot, transform") != std::string::npos);
    EXPECT_TRUE(capturedOutput.str().find("Decepticon, transform") != std::string::npos);
    EXPECT_TRUE(capturedOutput.str().find("Transformer, transform") != std::string::npos);
    EXPECT_TRUE(capturedOutput.str().find("Autobot, ulta") != std::string::npos);
    EXPECT_TRUE(capturedOutput.str().find("Decepticon, ulta") != std::string::npos);
    EXPECT_TRUE(capturedOutput.str().find("Transformer, ulta") != std::string::npos);
    EXPECT_TRUE(capturedOutput.str().find("Autobot, openFire") != std::string::npos);
    EXPECT_TRUE(capturedOutput.str().find("Decepticon, openFire") != std::string::npos);
    EXPECT_TRUE(capturedOutput.str().find("Transformer, openFire") != std::string::npos);


    
}

