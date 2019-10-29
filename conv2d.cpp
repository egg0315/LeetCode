    // OC: output channels, OH: output height, OW: output width
    // FC: feature channels, FH: feature map height, FW: feature map
    int oc,oh,ow;
    int fc,fh,fw;
    for (oc = 0; oc < OC; ++oc)
    {
        for (oh = 0; oh < OH; ++oh)
        {
            for (ow = 0; ow < OW; ++ow)
            {
                float val = 0.0f;
                int base_ow = ow * stride_w;
                int base_oh = oh * stride_h;
                int base_kernel = oc * FC * FH * FW;
                for (fc = 0; fc < FC; ++fc)
                {
                    for (fh = 0; fh < FH; ++fh)
                    {
                        for (fw = 0; fw < FW; ++fw)
                        {
                            int input_idx =
                                    (base_ow + fw) +
                                    (base_oh + fh) * IW +
                                    fc * IH * IW;
                            int filter_idx =
                                    fw +
                                    fh * FW +
                                    fc * FH * FW +
                                    base_kernel;
                            val += (input->data[input_idx] * filter->data[filter_idx]);
                        }
                    }
                }
                int output_idx =
                        ow +
                        oh * OW +
                        oc * OH * OW;
                output->data[output_idx] = val;
            }
        }
    }